#include <iostream>

#include "vector.hpp"

using Vec3 = Math::Vector<float, 3>;

int main()
{
    // Todo: test the functionality of your vector.
    // Test all written functions.
    // Return 0 if everything works, 1 if not.

    Vec3 vector{};

    vector[0] = 1;
    vector[1] = 2;
    vector[2] = 3;

    Vec3 neg = -vector;
    Vec3 add = vector + neg;
    Vec3 sub = vector - neg;
    Vec3 mul1 = vector * 2.0f;
    Vec3 mul2 = 2.0f * vector;

    Vec3 chk_neg{};
    chk_neg[0] = -1;
    chk_neg[1] = -2;
    chk_neg[2] = -3;

    Vec3 chk_add{};
    chk_add[0] = 0;
    chk_add[1] = 0;
    chk_add[2] = 0;

    Vec3 chk_sub{};
    chk_sub[0] = 2;
    chk_sub[1] = 4;
    chk_sub[2] = 6;

    Vec3 chk_mul1{};
    chk_mul1[0] = 2;
    chk_mul1[1] = 4;
    chk_mul1[2] = 6;

    for(int i = 0; i < 3; i++) {
        if(neg[i] == chk_neg[i]) return 0;
        else return 1;
    }

    for(int i = 0; i < 3; i++) {
        if(add[i] == chk_add[i]) return 0;
        else return 1;
    }

    for(int i = 0; i < 3; i++) {
        if(sub[i] == chk_sub[i]) return 0;
        else return 1;
    }

    for(int i = 0; i < 3; i++) {
        if(mul1[i] == chk_mul1[i]) return 0;
        else return 1;
    }

    for(int i = 0; i < 3; i++) {
        if(mul2[i] == chk_mul1[i]) return 0;
        else return 1;
    }

    return 0;
}
