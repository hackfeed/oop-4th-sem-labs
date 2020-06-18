#include "qt_factory.hpp"
#include "qt_drawer.hpp"

std::shared_ptr<BaseDrawer> QtFactory::CreateUi() const
{
    return std::make_shared<QtDrawer>();
}
