#include "inputquestclass.h"

inputquestclass::inputquestclass()
{

}
void inputquestclass::showx(boardhistorycclass *mbrd)
{
    brd=mbrd;
    this->setGeometry(1170,520,200,250);
    this->show();
    this->setFocus();
}
void inputquestclass::trans(int mindex)
{
    index=mindex;
    this->selectAll();
    QString str = this->textCursor().selectedText();
    int i=0;
    for(int x=0;x<9;x++)
    {
        for(int y=0;y<9;y++)
        {
            brd->brdhist[0]->boardget(index)->dataset(y,x,str[i].digitValue());
            i++;
            if(y==8){i++;}
        }
    }

}
void inputquestclass::mainwinclassset(MainWindow *mmainwin)
{
    mainwin=mmainwin;
}
void inputquestclass::keyPressEvent(QKeyEvent *event)
{
    if(event->key()==Qt::Key_Tab)
    {
        mainwin->wedit->setFocus();
        return;
    }
    if(event->key()==Qt::Key_Asterisk)
    {
        selectAll();
        QString mstr=textCursor().selectedText()+"000";
        insertPlainText(mstr);
        return;
    }
    if(event->key()==Qt::Key_Minus)
    {
        int idx=0;
        selectAll();
        QString mstr=textCursor().selectedText();
        QString mstr2="";
        for(int i=0;i<mstr.length();i++)
        {
            if(i%9==0)
            {
                mstr2+=mstr.mid(i,9)+"\n";
                idx++;
            }
            idx++;
        }
        clear();
        insertPlainText(mstr2);
        return;
    }
    QTextEdit::keyPressEvent(event);
}
