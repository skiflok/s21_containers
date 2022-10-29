#include <cstring>
#include <iostream>

template <typename T>
class abstract {
 public:
  abstract() {}
  abstract(int key, std::string name, int size) : key_(key), name_(name), size_(size) {
    InClass tmp(size);
    in_class_ = tmp;
  }
  virtual void Print();
  void SetKey(int key);
  void SetName(std::string name);

  class InClass {
   public:
    InClass() { std::cout << "constructor InClass" << std::endl; }
    InClass(size_t size) : size_(size), alloc_(size ? new T[size] : nullptr) {}
    ~InClass() {
      if (alloc_) {
        delete[] alloc_;
      }
      std::cout << "destructor InClass" << std::endl;
    }
    void operator=(const InClass& other ) {
      size_ = other.size_;
      alloc_ = new T[size_];
      std::memcpy(alloc_, other.alloc_, size_*sizeof (T));
    }
    T operator[](size_t i) {
      return alloc_[i];
    }
   protected:
    T* alloc_{};
    int size_;
  };

 protected:
  int key_{}, size_{};
  std::string name_{};
  InClass in_class_;
};

template <typename T>
class heir : public abstract<T> {
 public:
  heir() : abstract<T>() {}
  heir(int key, std::string name, bool brain)
      : abstract<T>(key, name), brain_(brain) {}
  void Print();

 protected:
  bool brain_{};
};