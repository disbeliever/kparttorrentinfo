#ifndef _HELLOPART_H_
#define _HELLOPART_H_
 
#include <kparts/part.h>
#include <kparts/factory.h>
#include <QFile>
#include <QLabel>

class kparttorrentinfo : public KParts::ReadOnlyPart
{
  Q_OBJECT
 
 private:
    QLabel *mMainWidget;
 
 public:
    kparttorrentinfo(QWidget *parentWidget, QObject *parent, const QVariantList&);
 
    QLabel* MainWidget() { return mMainWidget; };
 
    virtual ~kparttorrentinfo();
    bool openFile(){};
    bool saveFile(){};
};
 
#endif // _HELLOPART_H_
