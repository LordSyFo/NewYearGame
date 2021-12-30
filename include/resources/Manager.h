#pragma once

#include <resources/FontManager.h>

namespace NEG { namespace Resource {

class Manager {

public:
    explicit Manager();
    ~Manager();

    FontManager& GetFontManager();

private:
    FontManager font_manager_;

};

}
}