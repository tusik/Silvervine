#ifndef COMPARETOOLS_H
#define COMPARETOOLS_H

#include "../model/silvervinefile.h"
#include <QFileInfo>
/**
 * @brief The CompareTools class
 */
namespace Silvervine
{
#define FIRST_FEW_BYTES 8000
class CompareTools
{
public:
    CompareTools();
    static bool isSame(QString& source, QString& target);
    static bool isBinary(SilvervineFile& file);

    static int buffer_is_binary(const char* ptr, int64_t size);

};
};


#endif // COMPARETOOLS_H
