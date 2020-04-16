#include <iostream>
#include <string>

class Image
{
public:
    Image(std::string name) : m_name(name) {}
    virtual ~Image(){}

    virtual void Show() = 0;

protected:
    std::string m_name;
};


class BigImage : public Image
{
public:
    BigImage(std::string name) : Image(name){}
    virtual ~BigImage(){}

    void Show()
    {
        std::cout << "This is Big Image ..." << std::endl;
    }
};

class BigImageProxy : public Image
{
public:
    BigImageProxy(std::string name) : Image(name), m_bigImage(NULL) {}
    virtual ~BigImageProxy()
    {

    }

    void Show()
    {
        if (this->m_bigImage == NULL)
        {
            m_bigImage = new BigImage(this->m_name);
        }
        m_bigImage->Show();
    }

private:
    BigImage* m_bigImage;
};


int main()
{
    Image* Image = new BigImageProxy("Image.txt");
    Image->Show();
    delete Image;
    return 0;
}