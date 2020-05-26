#ifndef CODEFORMATHIGHLIGHT_H
#define CODEFORMATHIGHLIGHT_H
#include <QObject>
#include <QString>
#include <QStringList>
#include <QColor>

class codeformathighlight
{
public:
    codeformathighlight();
    ~codeformathighlight();
    QColor getTextColor(const QString &word);
    QColor includeLineColor(void);
    QColor starComment(void);


private:
    QStringList keyWords;



};

#endif // CODEFORMATHIGHLIGHT_H
