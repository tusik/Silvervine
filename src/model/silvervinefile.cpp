#include "silvervinefile.h"
#include <QTextStream>
#include <QCryptographicHash>
Silvervine::SilvervineFile::SilvervineFile(QObject* parent) : QFile(parent)
{

}

Silvervine::SilvervineFile::SilvervineFile(const QString& name): QFile(name)
{

}

bool Silvervine::SilvervineFile::fullOpen(QIODevice::OpenMode flags)
{
    if(open(flags))
    {
        QTextStream ts(this);
        int lineNum = 0;
        QCryptographicHash qhash(QCryptographicHash::Sha1);
        while(!ts.atEnd())
        {
            qhash.addData(ts.readLine().toStdString().c_str());
            SilvervineFileLine line;
            line.hash = qhash.result().toLongLong();
            line.lineNumber = lineNum;
            qhash.reset();
            fileLines.push_back(line);
            lineNum++;
        }
    }
    return false;
}
