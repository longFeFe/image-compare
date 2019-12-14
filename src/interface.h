#ifndef __INTERFACE__H_
#include "export.h"

#ifdef __cplusplus
extern "C" {
#endif

/***
** Author: chengxufei
** Date: 2019-12-13 17:42:27
** Param: sample_path  样本路径
**        refer_path   参照物路径
**        rank         比对阶数, 越大结果越可靠但是也越耗时. 最低取值 8
** Return: unsigned int， 取值范围 0 - 100000 , 数值越大表示相似度越高
** Description: 比对两个图片的相似程度 (jpg, other?)
**/
EXPORT_DLL unsigned int ImageSimilarity(const char* sample_path, const char* refer_path, int rank);
#ifdef __cplusplus
}
#endif
#endif