#include "kparttorrentinfo.h"

#include <QFile>
#include <QIODevice>
 
#include <kdemacros.h>
#include <kparts/genericfactory.h>
 
K_PLUGIN_FACTORY(torrentPartFactory, registerPlugin<kparttorrentinfo>();)  // produce a factory
K_EXPORT_PLUGIN(torrentPartFactory("hello","hello") )
 
kparttorrentinfo::kparttorrentinfo(QWidget *parentWidget, QObject *parent, const QVariantList&)
    : KParts::ReadOnlyPart(parent)
{
  KGlobal::locale()->insertCatalog("hello");
  // we need an instance
  setComponentData( torrentPartFactory::componentData() );

  initGUI();
}

void kparttorrentinfo::initGUI()
{
  window = new QWidget();
  box = new QHBoxLayout();

  labelComment = new QLabel();
  box->addWidget(labelComment);
  box->setAlignment(Qt::AlignTop);

  window->setLayout(box);
  setWidget(window);

  labelComment->setText("Comment:");

  editComment = new QLineEdit();
  editComment->setReadOnly(true);
  box->addWidget(editComment);
}
 
kparttorrentinfo::~kparttorrentinfo()
{
}

bool kparttorrentinfo::openFile()
{
  QFile file(url().pathOrUrl());
  if (!file.open(QIODevice::ReadOnly)) {
    labelComment->setText("failed to open file");
    return false;
  }

  QTextStream in(&file);
  in.setCodec("UTF-8");
  QString data = in.readLine();
  file.close();

  int idxComment = data.indexOf("comment");
  int idxCommentStart = data.indexOf(":", idxComment);

  bool ok;
  int lengthComment = data.mid(idxComment + 7, idxCommentStart - (idxComment + 7)).toInt(&ok, 10);
  if (ok) {
    QString comment = data.mid(idxCommentStart + 1, lengthComment);
    editComment->setText(comment);
  }

  emit completed();
  return true;
}
 
#include "kparttorrentinfo.moc"
