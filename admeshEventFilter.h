#ifndef ADMESHEVENTFILTER_H
#define ADMESHEVENTFILTER_H

#include <QObject>
#include <QFileOpenEvent>
#include "window.h"

class admeshEventFilter : public QObject
{
    Q_OBJECT
public:
    admeshEventFilter(QObject *parent, Window *w) : QObject(parent) {window = w;}
protected:
    bool eventFilter(QObject *obj, QEvent *event) {
        if (event->type() == QEvent::FileOpen) {
            QFileOpenEvent* ev = static_cast<QFileOpenEvent *>(event);
            window->openByFilename(ev->file().toStdString().c_str());
            return true;
        } else {
            return QObject::eventFilter(obj, event);
        }
    }
private:
    Window *window;
};

#endif // ADMESHEVENTFILTER_H
