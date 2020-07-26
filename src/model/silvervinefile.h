#ifndef SILVERVINEFILE_H
#define SILVERVINEFILE_H

#include <QFile>
#include <map>
namespace Silvervine
{

struct SilvervineFileLine
{
    int lineNumber = 0;
    qint64 hash = 0;
};

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
    bool fullOpen(OpenMode flags);
    FileType type = FileType::NONE;
private:
    std::vector<SilvervineFileLine> fileLines;
signals:

public slots:
};
};
#endif // SILVERVINEFILE_H
