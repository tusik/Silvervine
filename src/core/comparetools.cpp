#include "comparetools.h"
#include <QCryptographicHash>
#include <QDateTime>
#include <QDebug>
#include <QDataStream>
Silvervine::CompareTools::CompareTools()
{

}

bool Silvervine::CompareTools::isSame(QString& source, QString& target)
{
    QDateTime start = QDateTime::currentDateTime();
    qDebug() << start.toSecsSinceEpoch();
    QFileInfo sourceFileInfo(source);
    QFileInfo targetFileInfo(target);
    if(sourceFileInfo.isDir() || targetFileInfo.isDir())
    {
        return false;
    }
    if(sourceFileInfo.size() != targetFileInfo.size())
    {
        return false;
    }
    SilvervineFile sourceFile(source);
    SilvervineFile targetFile(target);
    QByteArray sourceMd5 = "0", targetMd5 = "1";
    if(sourceFile.open(QIODevice::ReadOnly) && targetFile.open(QIODevice::ReadOnly))
    {
        sourceMd5 = QCryptographicHash::hash(sourceFile.readAll(), QCryptographicHash::Sha1);
        targetMd5 = QCryptographicHash::hash(targetFile.readAll(), QCryptographicHash::Sha1);
        qDebug() << QDateTime::currentDateTime().toSecsSinceEpoch();
    }
    if(sourceFile.isOpen())
    {
        sourceFile.close();
    }
    if(targetFile.isOpen())
    {
        targetFile.close();
    }
    return sourceMd5 == targetMd5;
}

bool Silvervine::CompareTools::isBinary(Silvervine::SilvervineFile& file)
{
    int anchPostion = -1;
    if(!file.isOpen())
        if(!file.open(QIODevice::ReadOnly))
        {
            return anchPostion;
        }


    char* buffer = new char[FIRST_FEW_BYTES];

    int64_t actualSize = 0;
    actualSize = file.read(buffer, FIRST_FEW_BYTES);

    anchPostion = buffer_is_binary(buffer, actualSize);
    free(buffer);

    return anchPostion > 0;
}

int Silvervine::CompareTools::buffer_is_binary(const char* ptr, int64_t size)
{
    if(FIRST_FEW_BYTES < size)
    {
        size = FIRST_FEW_BYTES;
    }
    return !!memchr(ptr, 0, static_cast<size_t>(size));
}
