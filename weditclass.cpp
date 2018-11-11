#include"weditclass.h"
WEdit::WEdit(MainWindow *mw)
{
    pw=mw;
    this->setParent(mw);
}
void WEdit::keyPressEvent(QKeyEvent *event)
{
    if(event->key()==Qt::Key_Home)
    {
        selectAll();
        mbuf=textCursor().selectedText();
        this->setPlainText(QString(mbuf));
        return;
    }
    if(event->key()==Qt::Key_End)
    {
        this->setPlainText(QString(mbuf));
        return;
    }
    if(event->key()==Qt::Key_Enter || event->key()==Qt::Key_Return)
    {
        this->selectAll();
        pw->consolestringset(textCursor().selectedText());
        pw->update();
        this->setPlainText(QString(""));
        return;
    }
    if(event->key()==Qt::Key_Delete)
    {
        this->setPlainText(QString(""));
        pw->update();
        return;
    }
    if(event->key()==Qt::Key_Left)
    {
        QTextCursor cursor(textCursor());
        cursor.movePosition(QTextCursor::Left, QTextCursor::MoveAnchor);
        setTextCursor(cursor);
        pw->update();
        return;
    }
    if(event->key()==Qt::Key_Right)
    {
        QTextCursor cursor(textCursor());
        cursor.movePosition(QTextCursor::Right, QTextCursor::MoveAnchor);
        setTextCursor(cursor);
        pw->update();
        return;
    }
    if(event->key()==Qt::Key_Up)
    {
        QTextCursor cursor(textCursor());
        cursor.movePosition(QTextCursor::Up, QTextCursor::MoveAnchor);
        setTextCursor(cursor);
        pw->update();
        return;
    }
    if(event->key()==Qt::Key_Down)
    {
        QTextCursor cursor(textCursor());
        cursor.movePosition(QTextCursor::Down, QTextCursor::MoveAnchor);
        setTextCursor(cursor);
        pw->update();
        return;
    }
    //insertPlainText(QString(event->key()).toLower());
    QPlainTextEdit::keyPressEvent(event);
}
