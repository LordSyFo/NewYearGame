#include <resources/Manager.h>

using namespace NEG::Resource;

Manager::Manager() : font_manager_()
{
}

FontManager& Manager::GetFontManager()
{
    return font_manager_;
}

Manager::~Manager()
{
}