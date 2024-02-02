#ifndef SRC_SUBJECT_H_
#define SRC_SUBJECT_H_

class Observer; // forward declaration

/**
 * @brief Server, Model, Subject
 */
class Subject
{
  public:
	enum {ok = 0, failed = -1};

	int attach(const Observer& ob);
    int detach(const Observer& ob);
	void notify() const;

  private:
	enum {size = 4};  // number of allowed subjects
    const Observer* observers[size] = {nullptr}; // pointer to observer list
};

#endif
