#include "../../include/display-interfaces/display-intf.h"
#include "Adafruit_RA8875.h";

class TFT_DISPLAY : public DISPLAY_INTF
{
private:
    etl::vector<DISPLAY_ITEM_INTF *const, MAX_ELEMENTS> my_elements;
    Adafruit_RA8875 my_display_driver;

public:
    TFT_DISPLAY(uint8_t CSPin, uint8_t resetPin);
    ~TFT_DISPLAY();

    void addElement(DISPLAY_ITEM_INTF *const element) override;

    void updateScreen() override;

    bool removeElement(DISPLAY_ITEM_INTF const &element) override;

    etl::vector<DISPLAY_ITEM_INTF *const, MAX_ELEMENTS> getElements() const override;
};