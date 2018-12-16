//
// Created by seadream on 2018/12/16.
//
void ReorderOddEven(int *pData, unsigned int length) {
    if (pData == nullptr || length == 0) {
        return;
    }
    int *pBegin = pData;
    int *pEnd = pData + length - 1;

    while (true) {
        // 向后移动
        while (pBegin < pEnd && *pBegin & 0x1 != 0) {
            pBegin++;
        }
        while (pBegin < pEnd && *pBegin & 0x1 == 0) {
            pEnd--;
        }
        if (pBegin < pEnd) {
            int temp = *pBegin;
            *pBegin = *pEnd;
            *pEnd = temp;
        } else break;
    }
}

