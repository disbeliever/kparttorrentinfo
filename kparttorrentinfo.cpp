#include "kparttorrentinfo.h"
 
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
 
  mMainWidget = new QLabel();
  mMainWidget->setText("hello");
  setWidget( mMainWidget );
}
 
kparttorrentinfo::~kparttorrentinfo()
{
}
 
#include "kparttorrentinfo.moc"
