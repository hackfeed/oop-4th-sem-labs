#ifndef QT_FACTORY_HPP
#define QT_FACTORY_HPP

#include "abstract_factory.hpp"

class QtFactory : public AbstractFactory
{
public:
    std::shared_ptr<BaseDrawer> CreateUi() const override;
};

#endif