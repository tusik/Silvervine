#include "silvervinefile.h"
#include <QTextStream>
#include <QDataStream>
#include <QCryptographicHash>
#include <QDateTime>
#include <QDebug>
Silvervine::SilvervineFile::SilvervineFile(QObject* parent) : QFile(parent)
{

}

Silvervine::SilvervineFile::SilvervineFile(const QString& name): QFile(name)
{

}

bool Silvervine::SilvervineFile::fullOpen(QIODevice::OpenMode flags)
{
    qDebug() << "open file:" << this->fileName() << QDateTime::currentMSecsSinceEpoch();
    if(!isOpen())
    {
        if(!open(flags))
        {
            return false;
        }
    }
    return readFileByByte();
}

long Silvervine::SilvervineFile::isEndOfLine(char* ptr, unsigned long size)
{
    auto pos = memchr(ptr, '\r', size);
    if(nullptr != pos)
    {
        if(*(static_cast<char*>(pos) + 1) == '\n')
        {
            return static_cast<char*>(pos) - ptr + 1 ;
        }
        return static_cast<char*>(pos) - ptr;
    }
    else
    {
        return -1;
    }
}

bool Silvervine::SilvervineFile::readFileByByte()
{
    QDataStream ds(this);
    qint64 countSize = 0;
    QCryptographicHash qhash(QCryptographicHash::Sha1);
    SilvervineFileLine* forword = nullptr;
    char* buf = new char[READ_BUF_SIZE];
    int size = READ_BUF_SIZE;
    int actualSize = 0;
    QByteArray line;
    while((actualSize = ds.readRawData(buf, size)) > 0)
    {
        long bufPtr = 0, bufOffset = 0;

        while((bufOffset = isEndOfLine(buf + bufPtr, static_cast<unsigned long>(actualSize - bufOffset)))  >= 0)
        {

            line.append(buf + bufPtr, static_cast<int>(bufOffset) + 1);
            qhash.addData(line);
            SilvervineFileLine* sfline = new SilvervineFileLine();
            if(forword != nullptr)
            {
                forword->next = sfline;
            }
            sfline->forward = forword;
            forword = sfline;
            sfline->pos = line.size();
            sfline->hash = qhash.result().toHex();
            qhash.reset();
            fileLines.push_back(sfline);
            countSize += sfline->pos;
            bufPtr += bufOffset + 1;
            qDebug() << line;
            line.clear();

        }
        line.append(buf + bufPtr, static_cast<int>(bufOffset));
    }
    qDebug() << "open finished:" << this->fileName() << QDateTime::currentMSecsSinceEpoch();
    close();
    return true;
}
