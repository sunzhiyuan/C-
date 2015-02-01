#include<stdio.h>
class testconst
{
public:
    testconst( int*  const o);

    int * getConst() const {
        printf("getConst() const:%d\n",*mRemote);
        return mRemote;
    }

    int * getConst()  {
        printf("getConst():%d\n",*mRemote);
        return mRemote;
    }

private:
int *   const        mRemote;
};

testconst::testconst( int * const o)
:mRemote(o)
{
}

int main()
{
    int a = 3;
    int * const testO = &a;
    testconst * const test1 = new testconst(testO);
    test1->getConst();
    testconst * test2 = test1;
    test2->getConst();
    testconst const * test3 = new testconst(testO);
    test3->getConst();
    testconst * test4 = (testconst *)test3;
    test4->getConst();
    return 0;
}

//$ ./test 
//getConst():3
//getConst():3
//getConst() const:3
//getConst():3

