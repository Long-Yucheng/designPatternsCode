/*
* simple factory
*
*/

#include <iostream>
#include <string>

enum class TV_Brand
{
    ChangHong,
    Haier,
    Hisense
};

class creatTVInterface
{
public:
    virtual void createTv() = 0;
};

class ChangHong_TV_Factory : public creatTVInterface
{
public:
    void createTv() {
        std::cout << "create ChangHong TV" << std::endl;
    }
};

class Haier_TV_Factory : public creatTVInterface
{
public:
    void createTv() {
        std::cout << "create Haier TV" << std::endl;
    }
};

class Hisense_TV_Factory : public creatTVInterface
{
public:
    void createTv() {
        std::cout << "create Hisense TV" << std::endl;
    }
};

class TV_Factory
{
public:
    TV_Factory() {}
    ~TV_Factory() {}

    void createTV(TV_Brand brand) {
        switch (brand)
        {
        case TV_Brand::ChangHong:
        {
            ChangHong_TV_Factory ch;
            ch.createTv();
            break;
        }
        case TV_Brand::Haier:
        {
            Haier_TV_Factory haier;
            haier.createTv();
            break;
        }
        case TV_Brand::Hisense:
        {
            Hisense_TV_Factory hisense;
            hisense.createTv();
            break;
        }
        default:
            break;
        }
    }
};


int main()
{
    TV_Factory tvf;
    tvf.createTV(TV_Brand::ChangHong);
    tvf.createTV(TV_Brand::Haier);
    tvf.createTV(TV_Brand::Hisense);
    return 0;
}