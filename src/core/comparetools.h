#ifndef COMPARETOOLS_H
#define COMPARETOOLS_H

#include "../model/silvervinefile.h"
#include <QFileInfo>
/**
 * @brief The CompareTools class
 * @author tusik | image@by.cx
 * @date 2020-7-26
 */
#define FIRST_FEW_BYTES 8000
namespace Silvervine
{
struct DiffRecord
{


};

class CompareTools
{
public:
    CompareTools();
    static bool isSame(QString& source, QString& target);
    static bool isBinary(SilvervineFile& file);
    static DiffRecord diff(SilvervineFile& left, SilvervineFile& right);
    static int buffer_is_binary(const char* ptr, int64_t size);

};
};


#endif // COMPARETOOLS_H
