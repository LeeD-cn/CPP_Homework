# 第6次作业

1.编写程序：定义一个字符串类String，其私有成员为一个字符指针str。设计带缺省值的构造函数、复制构造函数、析构函数、设置新值函数Set、打印成员值函数Print。借助此String类，将操作符+重载函数设置为String类的友元函数，将操作符=重载函数设置为String类的成员函数，+和=重载操作符函数形参都用常引用方式。实现对操作符+和=的重载，使之能直接把两个String类类型的字符串进行串接并赋值。请设计各种情况调用此+和=重载操作符。例如：Strings1("abcd"),s2("efghij"),s3("lmnop"),s4,s5;s4=s1+s2+s3;s4.Print();//输出结果应该是abcdefghijlmnops5=s5+s3+s4;s5.Print();//输出结果应该是lmnopabcdefghijlmnop

2.编写程序：String类的定义同上题。借助此String类，将操作符+=重载函数设置为String类的成员函数，操作符函数形参用常引用方式。实现对操作符+=的重载，使s1+=s2;能直接把一个String类类型的字符串s2串接在另一个String类类型的字符串s1尾上，类似strcat(s1,s2);的功能，写+=操作符重载函数时需考虑各种极端情况(像s3+=s3自相加，把字符串s3串接在自己的尾部)。请设计各种情况调用此+=重载操作符。例如：Strings1("abcd"),s2("efghij"),s3("lmnop");s1+=s2;s1.Print();//输出结果应该是abcdefghijs3+=s3+=s2;s3.Print();//输出结果应该是lmnopefghijlmnopefghij
