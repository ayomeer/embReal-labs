#include "Subject.h"

#include "Observer.h"
//using namespace std;

int Subject::attach(const Observer& ob)
{
  for (int i = 0; i < size; ++i)
  {
    if (nullptr == observers[i]) // free entry found
    {
      observers[i] = &ob;
      return ok;   // success
    }
  }
  return failed;   // number of observers exceeded
}

int Subject::detach(const Observer& ob)
{
  for (int i = 0; i < size; ++i)
  {
		if (&ob == observers[i])
		{
		  observers[i] = nullptr;
		  return ok;  // success
		}
	}
  return failed;   // illegal observer
}

void Subject::notify() const
{
  for (int i = 0; i < size; ++i)
  {
    if (observers[i] != nullptr) // entry found
    {
      observers[i]->update();
    }
  }
}

