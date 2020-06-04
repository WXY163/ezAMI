#include "codeformathighlight.h"
#include <QStringList>
#include <QColor>


codeFormatHighlight::codeFormatHighlight(QWidget *parent) : QObject (parent)
{
    this->setParent(parent);
    declareKeyWords << "int" <<"long"<<"short"<<"bool";
    declareKeyWords<<"float"<<"double";
    declareKeyWords<<"char"<<"string"<<"vector"<<"list"<<"map"<<"void";
    declareKeyWords<<"unsigned";
    controlKeyWords<<"if"<<"else"<<"for"<<"while"<<"case"<<"switch"<<"return";

    setCommentFlag(false);



}

codeFormatHighlight::~codeFormatHighlight()
{

}

void codeFormatHighlight::textToProcess(QTextEdit *codeSpace, const QString &text)
{
    if (text.isEmpty())
    {
        codeSpace->insertPlainText("\r");
        return;
    }
    QStringList textList = text.split(" ");
    if(textList.value(0).contains("#include"))
    {
        codeSpace->setTextColor(QColor("purple"));
        codeSpace->insertPlainText(text + "\r");
        return;
    }
    if(textList.value(0).contains("//"))
    {
        codeSpace->setTextColor(QColor("green"));
        codeSpace->insertPlainText(text + "\r");
        return;
    }
    for(auto it = textList.begin(); it != textList.end(); it++)
    {
       if((*it).contains("(") && it == textList.end() - 1)
       {
           QStringList specialWord = (*it).split("(");
           for(auto is = specialWord.begin(); is != specialWord.end(); is++)
           {
               if(is == specialWord.end()-1)
               {
                   codeSpace->setTextColor(getTextColor(*is));
                   codeSpace->insertPlainText(*is + "\r");
               }
               else
               {
                   codeSpace->setTextColor(getTextColor(*is));
                   codeSpace->insertPlainText(*is);
                   codeSpace->setTextColor(QColor("black"));
                   codeSpace->insertPlainText("(");
               }
           }
       }
       else if ((*it).contains("(") && it != textList.end() - 1)
       {

           QStringList specialWord = (*it).split("(");
           for(auto is = specialWord.begin(); is != specialWord.end(); is++)
           {
               if(is == specialWord.end()-1)
               {
                   codeSpace->setTextColor(getTextColor(*is));
                   codeSpace->insertPlainText(*is + " ");
               }
               else
               {
                   codeSpace->setTextColor(getTextColor(*is));
                   codeSpace->insertPlainText(*is);
                   codeSpace->setTextColor(QColor("black"));
                   codeSpace->insertPlainText("(");
               }
           }

       }
       else
       {
           if(it == textList.end() - 1)
           {
               codeSpace->setTextColor(getTextColor(*it));
               codeSpace->insertPlainText(*it + "\r");
           }
           else
           {
               codeSpace->setTextColor(getTextColor(*it));
               codeSpace->insertPlainText(*it + " ");
           }

       }

    }


}

void codeFormatHighlight::setCommentFlag(bool flg)
{
    flag = flg;
}
QColor codeFormatHighlight::getTextColor(const QString &word)
{

    QString wordNoTab = word;
    if(getCommentFlag())
        return QColor("green");
    if(wordNoTab.contains("\t"))
        wordNoTab.replace("\t","");
    if(declareKeyWords.contains(wordNoTab))
        return QColor("blue");
    if(word.contains("/*") && word.contains("*/") && !word.contains("/*/"))
        return QColor("green");
    if(word.contains("/*"))
    {
        setCommentFlag(true);
        return QColor("green");
    }
    if(word.contains("*/"))
    {
        setCommentFlag(false);
    }
    if(controlKeyWords.contains(wordNoTab))
        return QColor("darkMagenta");
    if(word.contains("::"))
        return QColor("darkCyan");
    return QColor("black");

}
