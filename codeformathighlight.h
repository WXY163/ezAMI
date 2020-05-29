#ifndef CODEFORMATHIGHLIGHT_H
#define CODEFORMATHIGHLIGHT_H
#include <QObject>
#include <QWidget>
#include <QString>
#include <QStringList>
#include <QColor>
#include <QTextEdit>

class codeFormatHighlight : public QObject
{
public:
    codeFormatHighlight(QWidget *parent = nullptr);
    ~codeFormatHighlight();


    void textToProcess(QTextEdit *codeSpace, const QString &text);
    QColor getTextColor(const QString &word);
    QColor includeLineColor(void);
    //QColor starComment(void);
    void setCommentFlag(bool flg);
    bool getCommentFlag(void) const {return flag;}


private:
    QStringList declareKeyWords;
    QStringList controlKeyWords;
    QTextEdit *codingInterface = nullptr;
    bool flag;



};

#endif // CODEFORMATHIGHLIGHT_H
