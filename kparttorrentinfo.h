#ifndef _KPARTTORRENTINFO_H_
#define _KPARTTORRENTINFO_H_
 
#include <kparts/part.h>
#include <kparts/factory.h>
#include <QFile>
#include <QLabel>
#include <QtGui>

class kparttorrentinfo : public KParts::ReadOnlyPart
{
  Q_OBJECT
 
 private:
    QWidget *window;
    QLabel *labelComment;
    QLineEdit *editComment;
    QHBoxLayout *box;
    void initGUI();
 
 public:
    kparttorrentinfo(QWidget *parentWidget, QObject *parent, const QVariantList&);
 
    QWidget* MainWidget() { return window; };
 
    virtual ~kparttorrentinfo();
    bool openFile();
};
 
#endif // _KPARTTORRENTINFO_H_
