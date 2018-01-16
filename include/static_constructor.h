//
// Created by loic lopez on 16/01/2018.
//

#ifndef R_TYPE_STATIC_CONSTRUCTOR_H
#define R_TYPE_STATIC_CONSTRUCTOR_H

template<void(*ctor)()>
struct static_constructor
{
    struct constructor { constructor() { ctor(); } };
    static constructor c;
};

template<void(*ctor)()>
typename static_constructor<ctor>::constructor static_constructor<ctor>::c;

#endif //R_TYPE_STATIC_CONSTRUCTOR_H
