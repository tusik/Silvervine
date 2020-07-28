#ifndef SILVERVINEFILE_H
#define SILVERVINEFILE_H

#include <QFile>
#include <map>

namespace Silvervine
{
/**
 * @brief The SilvervineFileLine struct
 * @author tusik | image@by.cx
 * @date 2020-7-26
 */
struct SilvervineFileLine
{
    SilvervineFileLine* forward = nullptr;
    QByteArray hash = "";
    qint64 pos = 0 ;
    SilvervineFileLine* next = nullptr;
};
#define READ_BUF_SIZE 1024
/**
 * @brief The SilvervineFile class
 * @author tusik | image@by.cx
 * @date 2020-7-26
 */
class SilvervineFile : public QFile
{
    Q_OBJECT
    enum FileType
    {
        NONE = INT_MIN,
        Text = 1,
        Binary = 2,
        END = INT_MAX,
    };
public:
    explicit SilvervineFile(QObject* parent = nullptr);
    SilvervineFile(const QString& name);
    bool fullOpen(OpenMode flags = QIODevice::ReadOnly);
    FileType type = FileType::NONE;
    long isEndOfLine(char* ptr, unsigned long size);
private:
    std::vector<SilvervineFileLine*> fileLines;
    bool readFileByByte();
signals:

public slots:
};
};
#endif // SILVERVINEFILE_H
