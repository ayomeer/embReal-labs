#ifndef SRC_OBSERVER_H_
#define SRC_OBSERVER_H_

/**
 * @brief Observer abstract base class
 */
class Observer
{
  public:
		virtual void update() const = 0;
		virtual ~Observer() {}
};

#endif
