#ifndef SILVERVINEFILE_H
#define SILVERVINEFILE_H

#include <QFile>
#include <map>
namespace Silvervine
{

struct SilvervineFileLine
{
    int lineNumber = 0;
    QByteArray hash = "0";
};

class SilvervineFile : public QFile
{
    Q_OBJECT
public:
    explicit SilvervineFile(QObject* parent = nullptr);
    SilvervineFile(const QString& name);

    std::map<int, SilvervineFileLine> file;
signals:

public slots:
};
};
#endif // SILVERVINEFILE_H
