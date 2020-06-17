#include "qt_factory.hpp"

#include "qt_drawer.hpp"

std::shared_ptr<BaseDrawer> QtFactory::createGraphics() const
{
    return std::make_shared<QtDrawer>();
}
