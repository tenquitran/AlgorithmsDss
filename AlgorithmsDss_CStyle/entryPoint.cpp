// AlgorithmsDss_CStyle project: Defines the entry point for the console application.

#include "stdafx.h"

//////////////////////////////////////////////////////////////////////////

using namespace CommonLib;
using namespace AlgorithmsDss_CStyle;

//////////////////////////////////////////////////////////////////////////


int _tmain(int argc, _TCHAR* argv[])
{
    // TODO: temp; testing operations with AVL tree nodes
#if 0
    AvlTreeNode a;
    AvlTreeNode *pA = &a;

    pA->m_pRight = new AvlTreeNode();

    AvlTreeNode *pC = dynamic_cast<AvlTreeNode *>(pA->m_pRight);

    int tmp3 = 1;
#endif

    // CommonLib test.
#if 0
    try
    {
        // Test clearing of the console.

        ConsoleWnd console;

        TCHAR chars[] = { 'a', 'b', 'c', 'd', 'e' };

        const size_t ArrLen = _countof(chars);

        WORD colors[ArrLen] = { FOREGROUND_RED, FOREGROUND_GREEN, FOREGROUND_BLUE, FOREGROUND_RED, FOREGROUND_GREEN };

        for (size_t i = {}; i < 100; ++i)
        {
            size_t index = i % ArrLen;

            if (!console.clear(chars[index], colors[index]))
            {
                int tmp = 1;
            }

            ::Sleep(100);
        }
    }
    catch (const ExceptionA& ex)
    {
        std::cerr << ex.message() << '\n';
    }
#endif

    AvlTree avlTree;

    avlTree.insert(50);
    avlTree.insert(30);
    avlTree.insert(10);

    int arr[] = {12, 4, 7, -1, 5};

    selectionSort(arr, _countof(arr));

    double arr2[] = { 12.0, 4.0, 7.0, -1.0, 5.0 };

    selectionSort(arr2, _countof(arr2));

    GraphMixedAdjMatrix g1(5);

    int tmp2 = 1;

    return 0;
}
