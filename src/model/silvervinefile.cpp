#include "silvervinefile.h"

Silvervine::SilvervineFile::SilvervineFile(QObject* parent) : QFile(parent)
{

}

Silvervine::SilvervineFile::SilvervineFile(const QString& name): QFile(name)
{

}
