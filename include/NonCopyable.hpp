//
// Created by zbguo on 3/19/25.
//

#ifndef NONCOPYABLE_HPP
#define NONCOPYABLE_HPP



class NonCopyable {
    // this class should not be regarded as abstract class, but an attribute.
    // hence we do not use pure virtual function, but use access control here.
protected: // use protected to prevent direct instantiation
    NonCopyable() {}
    ~NonCopyable() = default;
    NonCopyable(const NonCopyable&) = delete;
    NonCopyable& operator=(const NonCopyable&) = delete;
};



#endif //NONCOPYABLE_HPP
