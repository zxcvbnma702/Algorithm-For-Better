# Java

- [Java](#java)
  - [Java设计思想](#java设计思想)
    - [OOP是什么](#oop是什么)
    - [JDK和JRE](#jdk和jre)
    - [面向对象的特征有哪些](#面向对象的特征有哪些)
    - [多态实现原理](#多态实现原理)
    - [重载（Overload）和重写（Override）的区别](#重载overload和重写override的区别)
      - [重写（Override）](#重写override)
      - [重载（Overload）](#重载overload)
    - [java是值传递还是引用传递](#java是值传递还是引用传递)
    - [抽象类和接口](#抽象类和接口)
    - [抽象类](#抽象类)
    - [接口](#接口)
    - [抽象类与接口的区别？](#抽象类与接口的区别)
    - [抽象和接口](#抽象和接口)
    - [接口的意义](#接口的意义)
    - [抽象类的意义](#抽象类的意义)
    - [接口是否可继承（extends）接口？抽象类是否可实现（implements）接口？抽象类是否可继承具体类（concrete class）？](#接口是否可继承extends接口抽象类是否可实现implements接口抽象类是否可继承具体类concrete-class)
  - [类和方法](#类和方法)
    - [一个".java"源文件中是否可以包含多个类（不是内部类）？有什么限制？](#一个java源文件中是否可以包含多个类不是内部类有什么限制)
    - [构造器（constructor）是否可被重写（override）](#构造器constructor是否可被重写override)
    - [静态变量和成员变量的区别](#静态变量和成员变量的区别)
    - [Object 中定义了哪些方法](#object-中定义了哪些方法)
    - [Cloneable 实现原理](#cloneable-实现原理)
    - [两个对象值相同(x.equals(y) == true)，但却可有不同的hash code，这句话对不对？](#两个对象值相同xequalsy--true但却可有不同的hash-code这句话对不对)
    - [如何实现对象的克隆](#如何实现对象的克隆)
    - [类中方法调用顺序](#类中方法调用顺序)
    - [是否可以从一个静态（static）方法内部发出对非静态（non-static）方法的调用？](#是否可以从一个静态static方法内部发出对非静态non-static方法的调用)
    - [抽象的（abstract）方法是否可同时是静态的（static）,是否可同时是本地方法（native），是否可同时被synchronized修饰？](#抽象的abstract方法是否可同时是静态的static是否可同时是本地方法native是否可同时被synchronized修饰)
    - [Super与this表示什么](#super与this表示什么)
    - [hashcode()和equals()的关系](#hashcode和equals的关系)
  - [内部类](#内部类)
    - [内部类](#内部类-1)
    - [匿名内部类](#匿名内部类)
    - [内部类的作用](#内部类的作用)
    - [静态嵌套类(Static Nested Class,或者叫静态内部类)和内部类（Inner Class）的不同](#静态嵌套类static-nested-class或者叫静态内部类和内部类inner-class的不同)
    - [Anonymous Inner Class(匿名内部类)是否可以继承其它类？是否可以实现接口？](#anonymous-inner-class匿名内部类是否可以继承其它类是否可以实现接口)
    - [内部类(非静态内部类)可以引用它的包含类（外部类）的成员吗？有没有什么限制？](#内部类非静态内部类可以引用它的包含类外部类的成员吗有没有什么限制)
    - [内部类访问局部变量的时候，为什么要加final](#内部类访问局部变量的时候为什么要加final)
    - [为什么内部类会持有外部类的引用？持有的引用是this？还是其它？](#为什么内部类会持有外部类的引用持有的引用是this还是其它)
  - [错误和异常](#错误和异常)
    - [java中的异常](#java中的异常)
    - [OOM](#oom)
    - [SOF](#sof)
    - [throw 和 throws](#throw-和-throws)
    - [Error和Exception有什么区别？](#error和exception有什么区别)
    - [运行时异常与受检异常有何异同？](#运行时异常与受检异常有何异同)
    - [列出一些你常见的运行时异常](#列出一些你常见的运行时异常)
  - [关键字和运算符](#关键字和运算符)
    - [==和equals的区别](#和equals的区别)
    - [\&和\&\&的区别；|和||的区别？](#和的区别和的区别)
    - [transient关键字](#transient关键字)
    - [修饰符的区别](#修饰符的区别)
    - [Java有没有goto？](#java有没有goto)
    - [在Java中，如何跳出当前的多重嵌套循环](#在java中如何跳出当前的多重嵌套循环)
    - [switch 是否能作用在byte 上，是否能作用在long 上，是否能作用在String上？](#switch-是否能作用在byte-上是否能作用在long-上是否能作用在string上)
    - [static](#static)
    - [final](#final)
    - [Java语言如何进行异常处理，关键字：throws、throw、try、catch、finally分别如何使用？](#java语言如何进行异常处理关键字throwsthrowtrycatchfinally分别如何使用)
    - [阐述final、finally、finalize的区别](#阐述finalfinallyfinalize的区别)
    - [finally 语句一定会执行吗](#finally-语句一定会执行吗)
    - [volatite 关键字](#volatite-关键字)
  - [基本类型和常用类](#基本类型和常用类)
    - [int和Integer有什么区别？为什么要有包装类？](#int和integer有什么区别为什么要有包装类)
    - [String 是基本数据类型吗？可以被继承吗？](#string-是基本数据类型吗可以被继承吗)
    - [枚举类型](#枚举类型)
    - [float f=3.4;是否正确？](#float-f34是否正确)
    - [short s1 = 1; s1 = s1 + 1;有错吗?short s1 = 1; s1 += 1;有错吗？](#short-s1--1-s1--s1--1有错吗short-s1--1-s1--1有错吗)
    - [Java中char 型变量中能不能存贮一个中文汉字，为什么?](#java中char-型变量中能不能存贮一个中文汉字为什么)
    - [数组有没有length()方法？String有没有length()方法？](#数组有没有length方法string有没有length方法)
    - [String、StringBuffer、StringBuilder](#stringstringbufferstringbuilder)
    - [String s = new String("xyz");创建了几个字符串对象？](#string-s--new-stringxyz创建了几个字符串对象)
    - [String 和基本数据类型之间的转换](#string-和基本数据类型之间的转换)
    - [实现字符串的反转](#实现字符串的反转)
    - [String为什么要设计成不可变](#string为什么要设计成不可变)
  - [集合](#集合)
    - [Collection 与 Collections的区别](#collection-与-collections的区别)
    - [Collection 与 Array区别](#collection-与-array区别)
    - [List、Set、Queue、Stack、Map的特点与用法](#listsetqueuestackmap的特点与用法)
    - [Vector、ArrayList、LinkedList的存储特性 \& 区别](#vectorarraylistlinkedlist的存储特性--区别)
    - [Map](#map)
      - [HashMap 与 LinkedHashMap、TreeMap的区别](#hashmap-与-linkedhashmaptreemap的区别)
      - [HashMap 与 Hashtable 的区别](#hashmap-与-hashtable-的区别)
      - [HashMap 与 ConcurrentHashMap 的区别](#hashmap-与-concurrenthashmap-的区别)
      - [HashCode作用](#hashcode作用)
      - [HashMap 1.7](#hashmap-17)
        - [基本概念](#基本概念)
        - [存储流程](#存储流程)
        - [为什么不直接采用经过hashCode（）处理的哈希码 作为 存储数组table的下标位置？](#为什么不直接采用经过hashcode处理的哈希码-作为-存储数组table的下标位置)
        - [为什么采用 哈希码 与运算(\&) （数组长度-1） 计算数组下标？](#为什么采用-哈希码-与运算-数组长度-1-计算数组下标)
        - [为什么在计算数组下标前，需对哈希码进行二次处理：扰动处理？](#为什么在计算数组下标前需对哈希码进行二次处理扰动处理)
        - [扩容机制](#扩容机制)
        - [总结](#总结)
      - [HashMap 1.8](#hashmap-18)
        - [扩容机制](#扩容机制-1)
      - [哈希表如何解决Hash冲突](#哈希表如何解决hash冲突)
      - [为什么HashMap具备下述特点：键-值（key-value）都允许为空、线程不安全、不保证有序、存储位置随时间变化](#为什么hashmap具备下述特点键-值key-value都允许为空线程不安全不保证有序存储位置随时间变化)
      - [为什么 HashMap 中 String、Integer 这样的包装类适合作为 key 键](#为什么-hashmap-中-stringinteger-这样的包装类适合作为-key-键)
      - [HashMap 中的 key若 Object类型， 则需实现哪些方法？](#hashmap-中的-key若-object类型-则需实现哪些方法)
    - [阻塞队列](#阻塞队列)
    - [Array/Linked](#arraylinked)
  - [多线程](#多线程)
    - [创建线程的方式有哪些？](#创建线程的方式有哪些)
    - [线程的状态有哪些？](#线程的状态有哪些)
    - [如何保证线程安全](#如何保证线程安全)
    - [ThreadPool](#threadpool)
    - [ThreadLocal](#threadlocal)
      - [ThreadLocal如何做到线程安全](#threadlocal如何做到线程安全)
      - [与同步机制区别](#与同步机制区别)
    - [什么是悲观锁和乐观锁？](#什么是悲观锁和乐观锁)
    - [synchronized](#synchronized)
    - [Lock、ReentrantLock](#lockreentrantlock)
    - [synchronized 与 Lock](#synchronized-与-lock)
    - [synchronized 和 volatile 关键字的区别](#synchronized-和-volatile-关键字的区别)
    - [谈一谈线程 sleep() 和 wait() 方法的区别？](#谈一谈线程-sleep-和-wait-方法的区别)
    - [谈谈 Java 线程中 notify 和 notifyAll 方法有什么区别](#谈谈-java-线程中-notify-和-notifyall-方法有什么区别)
    - [Java 中有哪些常见的锁](#java-中有哪些常见的锁)
  - [JVM](#jvm)
    - [内存分区](#内存分区)
      - [堆内存](#堆内存)
      - [栈内存](#栈内存)
      - [本地方法栈](#本地方法栈)
      - [静态方法区](#静态方法区)
      - [程序计数器](#程序计数器)
      - [总结](#总结-1)
    - [对象创建](#对象创建)
      - [指针碰撞](#指针碰撞)
      - [空闲列表](#空闲列表)
    - [对象内存布局](#对象内存布局)
    - [对象的访问方式](#对象的访问方式)
    - [对象存活判断](#对象存活判断)
    - [垃圾回收](#垃圾回收)
      - [复制](#复制)
    - [垃圾回收期器](#垃圾回收期器)
      - [标记整理](#标记整理)
      - [分代收集](#分代收集)
    - [类加载过程](#类加载过程)
    - [类加载器](#类加载器)
    - [双亲委派模型](#双亲委派模型)
    - [方法分派](#方法分派)
  - [Others](#others)
    - [Java 中有几种类型的流](#java-中有几种类型的流)
    - [xml 解析方式](#xml-解析方式)
    - [Serializable 和 Parcelable 区别](#serializable-和-parcelable-区别)
    - [Java 中深拷贝与浅拷贝的区别？](#java-中深拷贝与浅拷贝的区别)
    - [生产者消费者问题](#生产者消费者问题)
    - [泛型](#泛型)
    - [反射](#反射)
    - [什么时候用断言（assert）](#什么时候用断言assert)
    - [Java中的四种引用及应用场景](#java中的四种引用及应用场景)
    - [并发和并行的区别](#并发和并行的区别)
    - [字节流和字符流的区别](#字节流和字符流的区别)
    - [IO和NIO区别](#io和nio区别)
    - [JNI 与 NDK](#jni-与-ndk)
    - [大文件的复制](#大文件的复制)
    - [如何在Java中创建Immutable对象](#如何在java中创建immutable对象)
    - [for-each与常规for循环的效率对比](#for-each与常规for循环的效率对比)
    - [Comparable和Comparator接口是干什么的](#comparable和comparator接口是干什么的)
    - [用最有效率的方法计算2乘以8？](#用最有效率的方法计算2乘以8)
    - [请说说对HashMap的理解](#请说说对hashmap的理解)

![alt text](image-9.png)

## Java设计思想

### OOP是什么

面向对象编程（Object Oriented Programming）

### JDK和JRE

JDK:java development kit：java开发工具包，是开发人员所需要安装的环境（包含JRE）
JRE:java runtime environment：java运行环境，java程序运行所需要安装的环境

### 面向对象的特征有哪些

面向对象的特征有：抽象、封装、继承、多态

- **抽象**：抽象是将一类对象的共同特征总结出来构造类的过程，包括数据抽象和行为抽象两方面。抽象只关注对象有哪些属性和行为，并不关注这些行为的细节是什么。
- **封装**：隐藏对象的实现细节，仅对外公开接口，是针对一个对象来说的
- **多态**：多态性是指允许不同子类型的对象对同一消息作出不同的响应。简单的说就是用同样的对象引用调用同样的方法但是做了不同的事情
- **继承**：继承是从已有类得到继承信息创建新类的过程。提供继承信息的类被称为父类（超类、基类）；得到继承信息的类被称为子类（派生类）

![alt text](image-12.png)

### 多态实现原理

通过将 **子类对象实例** 赋值给 **父类引用变量**，使得编译时的静态变量 与 运行时的动态变量不一样，在调用方法 / 变量时，多态就发生了。

[jvm实现原理](https://github.com/Carson-Ho/AndroidLearning/blob/master/Material/Java/%E8%AF%AD%E8%A8%80%E7%89%B9%E6%80%A7/%E5%A4%9A%E6%80%81%E7%9A%84%E5%AE%9E%E7%8E%B0%E5%8E%9F%E7%90%86.md)

```java
// 设 B类是A类的子类

A b = new B();  //编译时变量 = A b 、运行时变量 = new B()
b.name;  // 调用了父类A的成员变量name 
b.move();  // 调用的是子类B重写后的2个方法move（）、content（）
b.content(); 

// 结论：因将 子类对象引用 赋值给 父类对象变量，即A a = new B()，即 编译时变量和运行时变量不一样，所以多态发生
```

### 重载（Overload）和重写（Override）的区别

> 重写（Override）和重载（Overload）其实并无联系，可能是因为名称相似，容易引起混淆 > 重写发生在运行时，重载发生在编译期

![alt text](image-13.png)
![alt text](image-14.png)

#### 重写（Override）

重写是针对父类和子类来说的，是在子类中重写父类的方法。

- 要求方法名，参数个数和类型必须相同
- 返回的数据类型必须与父类相同或者是其子类
- 访问修饰符的限制一定要大于父类中该方法的访问修饰符（public>protected>default>private）
- 重写方法一定不能抛出新的检查异常或者比被重写方法申明更加宽泛的检查型异常

#### 重载（Overload）

重载是针对一个类说的，是Java中多态性的一种表现

- 要求方法名相同
- 必须有不同的参数列表
- 可以有不同的返回类型
- 可以有不同的修饰符
- 可以抛出不同的异常。

> 扩展：华为的面试题中曾经问过这样一个问题 - "为什么不能根据返回类型来区分重载"
答：因为调用时不能指定类型信息，编译器不知道你要调用哪个函数。例如：
float max(int a, int b);
int max(int a, int b);
当调用max(1, 2);时无法确定调用的是哪个。
参考：<https://www.zhihu.com/question/21455159/answer/59874307>

### java是值传递还是引用传递

java是值传递。可以理解为传入的是一个引用的副本，指向统一地址。当值改变时，原引用和副本指向地址中的值都变了；当副本指向的地址改变，指向新值时，原引用指向的地址没有改变，原值也没有改变。

### 抽象类和接口

![alt text](image-15.png)

### 抽象类

![alt text](image-16.png)

```java
// 定义1抽象动物类Animal，提供抽象方法 = cry()
public abstract class Animal {  
    public abstract void cry();  
}  
 
// 猫、狗 = 动物类的子类
// 由于cry（）为抽象方法，所以Cat、Dog必须要实现cry（）
public class Cat extends Animal{  
  
    @Override  
    public void cry() {  
        System.out.println("猫叫：喵喵...");  
    }  
}  
  
public class Dog extends Animal{  
  
    @Override  
    public void cry() {  
        System.out.println("狗叫:汪汪...");  
    }  
  
}  

// 测试
public class Test {  
  
    public static void main(String[] args) {  
        Animal a1 = new Cat();  
        Animal a2 = new Dog();  
          
        a1.cry();  
        a2.cry();  
    }  
}  

// 运行结果
猫叫：喵喵...  
狗叫:汪汪... 
```

### 接口

![alt text](image-17.png)

```java
interface Demo{
    void method1();
    void method2();
}
  
class Test implements Demo{  
    void method1();
    void method2();
} 
```

### 抽象类与接口的区别？

![alt text](image-18.png)

1. 抽象类可以提供成员方法的实现细节，而接口中只能存在 ``public`` 抽象方法；
2. 抽象类中的成员变量可以是各种类型的，而接口中的成员变量只能是 ``public static final`` 类型的；
3. 接口中不能含有构造器、静态代码块以及静态方法，而抽象类可以有构造器、静态代码块和静态方法；
4. 一个类只能继承一个抽象类，而一个类却可以实现多个接口；
5. 抽象类访问速度比接口速度要快，因为接口需要时间去寻找在类中具体实现的方法；
6. 如果你往抽象类中添加新的方法，你可以给它提供默认的实现。因此你不需要改变你现在的代码。如果你往接口中添加方法，那么你必须改变实现该接口的类。
7. 接口更多的为了**约束类**的行为，可用于解耦，而抽象类更加侧重于**代码复用**。

### 抽象和接口

1. 抽象类不能有对象（不能用 new 关键字来创建抽象类的对象）
2. 抽象类中的抽象方法必须在子类中被重写
3. 接口中的所有属性默认为：``public static final``
4. 接口中的所有方法默认为：``public abstract``

### 接口的意义

1. 规范
2. 扩展
3. 回掉
4. java是单继承的

### 抽象类的意义

1. 为其他子类提供一个公共的类型
2. 封装子类中重复定义的内容
3. 定义抽象方法,子类可以有不同的实现

### 接口是否可继承（extends）接口？抽象类是否可实现（implements）接口？抽象类是否可继承具体类（concrete class）？

1. 接口可以继承接口,而且支持多重继承
2. 抽象类可以实现(implements)接口
3. 抽象类是否可继承具体类,也可以继承抽象类

## 类和方法

### 一个".java"源文件中是否可以包含多个类（不是内部类）？有什么限制？

一个".java"文件内可以有多个类，但只能有**一个类**是公开的

### 构造器（constructor）是否可被重写（override）

构造器不能被继承，因此不能被重写，但可以被重载

### 静态变量和成员变量的区别

![alt text](image-29.png)

- 静态变量属于类，被多个实例共享，成员变量属于实例
- 静态变量储存在方法区，成员变量在堆
- 静态变量在类加载时候存在，成员变量在实例加载之后存在
- 静态方法可以直接使用静态变量，不能直接使用成员变量

### Object 中定义了哪些方法

![alt text](image-27.png)

### Cloneable 实现原理

``Cloneable``是一个接口，没有具体方法

clone方法是Object类中方法，会检查当前实例是否实现``Cloneable``接口，没有实现则抛出异常，实现了就调用native方法进行clone（clone进行的是浅拷贝），源码如下

```java
protected Object clone() throws CloneNotSupportedException {
        if (!(this instanceof Cloneable)) {
            throw new CloneNotSupportedException("Class " + getClass().getName() +
                                                 " doesn't implement Cloneable");
        }
        return internalClone();
    }
```

### 两个对象值相同(x.equals(y) == true)，但却可有不同的hash code，这句话对不对？

不对。

java 规定，值相同，hashCode一定要相同；hashCode相同，值可能不同
如果值相同，hashCode不同，就会造成Hashset、HashMap等借助hashCode实现的数据结构出现错乱，相同的值或者key可能出现多次

### 如何实现对象的克隆

1. 通过实现``Cloneable``接口实现clone：这里要注意深拷贝和浅拷贝问题，如果该类内部变量是引用类型的，并且内部变量类没有实现``Cloneable``接口，那么克隆出来的该变量是浅拷贝的（只是复制了引用，两个引用指向统一实例）
2. 通过实现``Serializable``接口，通过对象的序列化和反序列化实现克隆。

```java
import java.io.ByteArrayInputStream;
import java.io.ByteArrayOutputStream;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.io.Serializable;

public class MyUtil {

    private MyUtil() {
        throw new AssertionError();
    }

    @SuppressWarnings("unchecked")
    public static <T extends Serializable> T clone(T obj) throws Exception {
        ByteArrayOutputStream bout = new ByteArrayOutputStream();
        ObjectOutputStream oos = new ObjectOutputStream(bout);
        oos.writeObject(obj);

        ByteArrayInputStream bin = new ByteArrayInputStream(bout.toByteArray());
        ObjectInputStream ois = new ObjectInputStream(bin);
        return (T) ois.readObject();

        // 说明：调用ByteArrayInputStream或ByteArrayOutputStream对象的close方法没有任何意义
        // 这两个基于内存的流只要垃圾回收器清理对象就能够释放资源，这一点不同于对外部资源（如文件流）的释放
    }
}
```

### 类中方法调用顺序

指出下面程序的运行结果

```java
class A {

    static {
        System.out.print("1");
    }

    public A() {
        System.out.print("2");
    }
}

class B extends A {

    static {
        System.out.print("a");
    }

    public B() {
        System.out.print("b");
    }
}

public class Hello {

    public static void main(String[] args) {
        A ab = new B();
        ab = new B();
    }

}
```

执行结果：1a2b2b。

创建对象时构造器的调用顺序是：  父类静态初始化块  -> 子类静态初始化块 -> 父类初始化块 ->调用了父类构造器 -> 子类初始化块 -> 调用子类的构造器

### 是否可以从一个静态（static）方法内部发出对非静态（non-static）方法的调用？

不可以，静态方法只能访问静态成员，因为非静态方法的调用要先创建对象，在调
用静态方法时可能对象并没有被初始化

### 抽象的（abstract）方法是否可同时是静态的（static）,是否可同时是本地方法（native），是否可同时被synchronized修饰？

- 抽象方法不能是静态的：静态方法不能被子类重写，抽象方法必须被子类重写，冲突；
- 抽象方法不能是native的：本地方法是由本地代码（如C代码）实现的方法，而抽象方法是没有实现的，也是矛盾的
- 抽象方法不能用sychronized：synchronized和方法的实现细节有关，抽象方法不涉及实现细节，因此也是相互矛盾的

### Super与this表示什么

Super表示当前类的父类对象;This表示当前类的对象

### hashcode()和equals()的关系

充分不必要的关系

## 内部类

### 内部类

1. 非静态内部类没法在外部类的静态方法中实例化。
2. 非静态内部类的方法可以直接访问外部类的所有数据，包括私有的数据。
3. 在静态内部类中调用外部类成员，成员也要求用 static 修饰。
4. 创建静态内部类的对象可以直接通过外部类调用静态内部类的构造器
5. 创建非静态的内部类的对象必须先创建外部类的对象，通过外部类的对象调用内部类的构造器。

### 匿名内部类

1. 匿名内部类不能定义任何静态成员、方法
2. 匿名内部类中的方法不能是抽象的
3. 匿名内部类必须实现接口或抽象父类的所有抽象方法
4. 匿名内部类不能定义构造器
5. 匿名内部类访问的外部类成员变量或成员方法必须用 final 修饰

### 内部类的作用

1. 内部类可以很好的实现隐藏
2. 内部类拥有外围类的所有元素的访问权限
3. 可以间接实现多重继承
4. 可以避免修改接口而实现同一个类中两种同名方法的调用

### 静态嵌套类(Static Nested Class,或者叫静态内部类)和内部类（Inner Class）的不同

![alt text](image-28.png)

1. 内部类持有外部类的引用（this），静态内部类不持有
2. 因为持有外部类的引用，所以new时需要先有外部类的实例，再用外部类实例new内部类实例，举例：new Outer().new Inner();

> 扩展：在Android中，因为内部类持用外部类引用，所以容易造成内存泄漏，一般推荐使用静态内部类

### Anonymous Inner Class(匿名内部类)是否可以继承其它类？是否可以实现接口？

可以继承其他类，也可以实现接口

```java
//这里new的就是一个匿名内部类，这个匿名内部类实现了View.OnClickListener接口。所以匿名内部类本身一定会继承或实现一个且仅一个类或者接口
btn.setOnClickListener(new View.OnClickListener(){
    @Override
    public void onClick(View view){
    
    }
    })
```

### 内部类(非静态内部类)可以引用它的包含类（外部类）的成员吗？有没有什么限制？

一个内部类对象可以访问创建它的外部类对象的成员，包括私有成员。
应用局部变量，局部变量前要加final修饰

### 内部类访问局部变量的时候，为什么要加final

- 内部类和局部变量生命周期不同（方法结束后局部变量的生命周期就结束了，而内部类只要有引用就不结束，内部类的生命周期>=局部变量）
- Java为了解决这一问题，会在编译时在内部类的构造方法里边，将局部变量作为参数传入内部类
- 这就造成了局部变量如果改变，内部类不知情的场景，所以要加final，保证引用不可改变

> 扩展：在java8中，可以不使用final关键字，但是如果我们改变局部变量的引用，编译会发生错误，从而保证了局部变量的引用不变。

### 为什么内部类会持有外部类的引用？持有的引用是this？还是其它？

内部类虽然和外部类写在同一个文件中， 但是编译完成后， 还是生成各自的class文件，内部类通过this访问外部类的成员。

- 编译器自动为内部类添加一个成员变量，这个成员变量的类型和外部类的类型相同， 这个成员变量就是指向外部类对象
- 编译器自动为内部类的构造方法添加一个参数，参数的类型是外部类的类型， 在构造方法内部使用这个参数为内部类中添加的成员变量赋值；
- 在调用内部类的构造函数初始化内部类对象时，会默认传入外部类的引用。

## 错误和异常

![alt text](image-34.png)

### java中的异常

基类是``Throwable``，``Error``和``Exception``继承自``Throwable``
Error通常是系统抛出来的，也可以catch到，但一般不可恢复，开发是也不做处理
``Exception``分为受检查异常和不受检查异常，受检查异常会在编译时强制要求我们try/catch

### OOM

![alt text](image-32.png)

### SOF

![alt text](image-33.png)

### throw 和 throws

throw:抛出异常
throws：在方法声明处使用，表示此方法可能抛出的异常，调用此方法处需要处理这些异常。

### Error和Exception有什么区别？

1. Error 是系统中的错误，不可预料的，这种异常发生后，会导致程序立即崩溃。只能通过修改代码，使错误不在出现，这种错误 无法被捕获。
2. Exception 则是可以预料的。在程序中如果过感觉某段代码会出现 异常，则可以使用 ``try catch`` 进行捕获，或者直接抛出异常。Exception 可分为 编译时异常(CheckedException) 和 运行时异常(RuntimeException)。运行时异常可以 忽略捕获操作(RuntimeException)，编译时异常必须使用 ``try catch`` 进行捕获。

### 运行时异常与受检异常有何异同？

``checked exception``:这种异常，JAVA编译器强制要求我们必需对出现的这些异常进行try/catch或者继续上抛

``runtime exception``:出现运行时异常后，系统会把异常一直往上层抛，一直遇到处理代码。如果没有处理块，到最上层，如果是多线程就由Thread.run()抛出，如果是单线程就被main()抛出。抛出之后，如果是线程，这个线程也就退出了。如果是主程序抛出的异常，那么这整个程序也就退出了

### 列出一些你常见的运行时异常

NullPointerException （空指针异常）
ClassCastException （类转换异常）
IndexOutOfBoundsException （下标越界异常）
IllegalArgumentException （非法参数异常）

## 关键字和运算符

### ==和equals的区别

![alt text](image-25.png)

1. ``==`` 是 Java 中的一个操作符，用于比较两个变量的值是否相等。对于基本数据类型（如 int、float 等），``==`` 比较的是它们的值；对于引用类型（如对象），``==``比较的是它们在内存中的地址。
2. ``equals()`` 是 Object 类中定义的方法，用于比较两个对象是否相等。默认情况下，``equals()`` 方法与 ``==`` 的作用是一样的，即比较两个对象的内存地址。但是，可以通过重写 ``equals()`` 方法来改变其行为，使其比较对象的内容而不是地址。

### &和&&的区别；|和||的区别？

&有两种用法：(1)按位与；(2)逻辑与，我们这里说的是逻辑与。
与运算要求左右两端的布尔值都是true整个表达式的值才是true
&&运算符是短路逻辑与运算，如果&&左边的表达式的值是false，右边的表达式会被直接短路掉，不会进行运算
&左右两边的表达式都会计算，我们常用&&，比如``if(username != null &&!username.equals("hahaha")){}``

### transient关键字

如果用``transient``声明一个实例变量，当对象存储时，它的值不需要维持。换句话来说就是，用``transient``关键字标记的成员变量不参与序列化过程

作用：防止字段被序列化，即 被该关键字修饰 的字段，仅存于 调用者的内存，而不会写到磁盘里持久化

### 修饰符的区别

修饰符一共有四个：private、protected、public和default（也有人管默认叫friendly）

private：私有的，除自己外任何类不能使用
protected：同包可以使用，其他包子类可以使用
public：任何类可以使用
default：同包可以使用，其他包不能使用

修饰符|当前类|同 包|子 类|其他包
---|---|---|---|---
public|√|√|√|√
protected|√|√|√|×
default|√|√|×|×
private|√|×|×|×

### Java有没有goto？

``goto`` 和 ``const`` 是Java中的保留字，在目前版本的Java中没有使用。

### 在Java中，如何跳出当前的多重嵌套循环

在最外层循环前加一个标记如A，然后用break A;可以跳出多重循环
(应该避免使用带标签的break和continue，因为它不会让你的程序变得更优雅)。

### switch 是否能作用在byte 上，是否能作用在long 上，是否能作用在String上？

在Java 5以前，switch(expr)中，expr只能是byte、short、char、int
Java 5开始，Java中引入了枚举类型，expr也可以是enum类型
从Java 7开始，expr还可以是字符串（String）
**long类型不支持**

### static

可以修饰内部类（静态内部类）
可以修饰成员变量，该变量属于类，被所有实例共享
可以修饰方法，该方法属于类，被所有实例共享
可以修饰代码块（静态代码块），该代码块在第一次被加载时被调用

``static`` 关键字修饰的方法或者变量不需要依赖于对象来进行访问，只要类被加载了，就可以通过类名去进行访问。

1. 静态变量被所有的对象所共享，在内存中只有一个副本，它当且仅当在类初次加载时会被初始化。
2. 能通过 this 访问静态成员变量吗?所有的静态方法和静态变量都可以通过对象访问（只要访问权限足够）
3. ``static`` 是不允许用来修饰局部变量

### final

``final``可以声明成员变量、方法、类以及本地变量

1. ``final`` 成员变量必须在声明的时候初始化或者在构造器中初始化，否则就会报编译错误
2. ``final`` 变量是只读的
3. ``final`` 申明的方法不可以被子类的方法重写
4. ``final`` 类通常功能是完整的，不能被继承
5. ``final`` 变量可以安全的在多线程环境下进行共享，而不需要额外的同步开销
6. `final` 关键字提高了性能，JVM 和 Java 应用都会缓存 ``final`` 变量，会对方法、变量及类进行优化
7. 方法的内部类访问方法中的局部变量，但必须用 ``final`` 修饰才能访问

### Java语言如何进行异常处理，关键字：throws、throw、try、catch、finally分别如何使用？

- Java通过面向对象的方法进行异常处理，把各种不同的异常进行分类在Java中，每个异常都是一个对象，它是Throwable类或其子类的实例。当一个方法出现异常后便抛出一个异常对象，该对象中包含有异常信息，调用这个对象的方法可以捕获到这个异常并可以对其进行处理。
- Java的异常处理是通过5个关键词来实现的：try、catch、throw、throws和finally。一般情况下是用try来执行一段程序，如果系统会抛出（throw）一个异常对象，可以通过它的类型来捕获（catch）它，或通过总是执行代码块（finally）来处理；try用来指定一块预防所有异常的程序；catch子句紧跟在try块后面，用来指定你想要捕获的异常的类型；throw语句用来明确地抛出一个异常；throws用来声明一个方法可能抛出的各种异常（当然声明异常时允许无病呻吟）；finally为确保一段代码不管发生什么异常状况都要被执行；
- try语句可以嵌套，每当遇到一个try语句，异常的结构就会被放入异常栈中，直到所有的try语句都完成。如果下一级的try语句没有对某种异常进行处理，异常栈就会执行出栈操作，直到遇到有处理这种异常的try语句或者最终将异常抛给JVM。

### 阐述final、finally、finalize的区别

这是三个不同的概念，只是因为长得较像而被出成了一道题

![alt text](image-30.png)

**final**
``final``是一个修饰符，用来修饰类，变量，方法

``final``修饰的类不能被继承
``final``修饰的方法不能被重写
``final``修饰的成员变量是不可变的，如果成员变量是基本数据类型，初始化之后成员变量的值不能被改变，如果成员变量是引用类型，那么它只能指向初始化时指向的那个对象，不能再指向别的对象，但是对象当中的内容是允许改变的

**finally**
`finally`与``try``，``catch``一起搭配使用，不论是否``catch``到异常，``finally``中的内容都会执行

**finalize**
``finalize``是Object类中的方法，垃圾回收器在垃圾回收时会调用该方法，我们可以在子类中重写该方法来做一些清理工作

### finally 语句一定会执行吗

在极特殊的情况下可能不执行

- 调用了System.exit()方法
- JVM崩溃了

### volatite 关键字

![alt text](image-31.png)

## 基本类型和常用类

![alt text](image-20.png)

### int和Integer有什么区别？为什么要有包装类？

int是基本类型，Integer是int的包装类型
包装类型可以有一些自己的方法，引入包装类型可以使java更好的面向对象

```java
// 扩展1：
// java5中引入了自动拆装箱功能，例如在比较时可以自动拆装箱
class AutoUnboxingTest {

    public static void main(String[] args) {
        Integer a = new Integer(3);
        Integer b = 3;                  // 将3自动装箱成Integer类型
        int c = 3;
        System.out.println(a == b);     // false 两个引用没有引用同一对象
        System.out.println(a == c);     // true a自动拆箱成int类型再和c比较
    }
}
```

![alt text](image-19.png)

![alt text](image-21.png)

1. 数据类型不同：``int`` 是基础数据类型，而 ``Integer`` 是包装数据类型；
2. 默认值不同：``int`` 的默认值是 0，而 ``Integer`` 的默认值是 ``null``；
3. 内存中存储的方式不同：``int`` 在内存中直接存储的是数据值，而 ``Integer`` 实际存储的是对象引用，当 new 一个 ``Integer`` 时实际上是生成一个指针指向此对象；
4. 实例化方式不同：``Integer`` 必须实例化才可以使用，而 ``int`` 不需要；
5. 变量的比较方式不同：``int`` 可以使用 ``==`` 来对比两个变量是否相等，而 ``Integer`` 一定要使用 ``equals`` 来比较两个变量是否相等。

### String 是基本数据类型吗？可以被继承吗？

``String`` 是引用类型，底层用 ``char`` 数组实现的。因为 ``String`` 是 ``final`` 类，在 java 中被 ``final`` 修饰的类不能被继承， 因此 ``String``当然不可以被继承。

![alt text](image-24.png)

### 枚举类型

![alt text](image-22.png)

### float f=3.4;是否正确？

答:不正确。3.4是双精度数，将双精度型（double）赋值给浮点型（float）属于下转型（down-casting，也称为窄化）会造成精度损失，因此需要强制类型转换float f =(float)3.4; 或者写成float f =3.4F;。

### short s1 = 1; s1 = s1 + 1;有错吗?short s1 = 1; s1 += 1;有错吗？

- 对于s``hort s1 = 1; s1 = s1 + 1``;由于1是int类型，因此s1+1运算结果也是int 型，需要强制转换类型才能赋值给short型。
- ``short s1 = 1; s1 += 1``;可以正确编译，因为``s1+= 1``;相当于``s1 = (short)(s1 + 1)``;其中有隐含的强制类型转换。

### Java中char 型变量中能不能存贮一个中文汉字，为什么?

Java中 char型变量用来存储Unicode编码的字符，unicode编码字符集中包含了汉字，所以char类型可以储存汉字 char类型占两个字节

### 数组有没有length()方法？String有没有length()方法？

数组有length属性，String有length()方法

### String、StringBuffer、StringBuilder

![alt text](image-26.png)

1. ``String`` 是 ``final`` 类，不能被继承。对于已经存在的 ``Stirng`` 对象，修改它的值，就是重新创建一个对象
2. ``StringBuffer`` 是一个类似于 ``String`` 的字符串缓冲区，使用 ``append()`` 方法修改
``Stringbuffer`` 的值，使用 ``toString()`` 方法转换为字符串，是线程安全的
3. ``StringBuilder`` 用来替代于 ``StringBuffer``，``StringBuilder`` 是非线程安全的，速度更快
4. 执行速度：``StringBuilder`` > ``StringBuffer`` > ``String``

```java
循环中使用+举例：
String str = "hello,world!";
        String result = "";

        for (int i = 0; i < loopCount; i++) {
            result += str;
        }
这个时候编译器会优化成
String str = "hello,world!";
        String result = "";

        for (int i = 0; i < loopCount; i++) {
            result = new StringBuilder(result).append(str).toString();
        }
多次new StringBuilder造成了性能浪费。
```

```java
扩展例题
class StringEqualTest {

    public static void main(String[] args) {
        String s1 = "Programming";
        String s2 = new String("Programming");
        String s3 = "Program";
        String s4 = "ming";
        String s5 = "Program" + "ming";
        String s6 = s3 + s4;
        System.out.println(s1 == s2); // false
        System.out.println(s1 == s5); //true
        System.out.println(s1 == s6); //false
        System.out.println(s1 == s6.intern()); //true
        System.out.println(s2 == s2.intern()); //false
    }
}

解析：1. String是引用类型，这里 == 比较的是引用是否相同，即是否指向相同的地址
     2. 在new String对象时，会产生一个新的对象，并不会使用常量池中的字符串
     3. intern会在常量池中寻找该字符串（如果没有责新建），并返回他的地址
```

### String s = new String("xyz");创建了几个字符串对象？

两个对象，一个是静态区的"xyz";一个是用new创建在堆上的对象。

### String 和基本数据类型之间的转换

String 转基本数据类型：调用基本数据类型对应包装类的parseXXX(String)或valueOf(String)方法
基本数据类型转String：基本数据类型+“”；String.valueof(12)

### 实现字符串的反转

> 方法有很多，可以用StringBuffer/StringBuilder的reverse方法，这里reverse是通过位移实现的

再举例一种递归方法：

```java
public String reverse(String originString){
    if(originString == null || originString.length <= 1)
    return originString;
    return reverse(originString.subString(1)) + originString.charAt(0);
    }
```

### String为什么要设计成不可变

1. 安全性

> 线程安全，不可变天生线程安全
String常被用作HashMap的key，如果可变会引有安全问题，如两个key相同
String常被用作数据库或接口的参数，可变的话也会有安全问题

2. 效率

> 通过字符串池可以节省很多空间
每个String对应一个hashcode，再次使用的话不用重新计算

## 集合

![alt text](image-37.png)

### Collection 与 Collections的区别

Collection：一个接口，是所有集合（如Set、List）容器的顶层父接口
Collections：一个工具类，提供了一系列的静态方法来辅助容器操作

### Collection 与 Array区别

![alt text](image-38.png)

### List、Set、Queue、Stack、Map的特点与用法

![alt text](image-39.png)
![alt text](image-40.png)

### Vector、ArrayList、LinkedList的存储特性 & 区别

![alt text](image-41.png)
![alt text](image-42.png)

1. ``ArrayList``是基于数组的数据结构，分配的是一段连续的内存空间。 新增数据的时候效率低，因为新增一个元素的时候都要考虑数组的容量，即扩容判断，而后进行新增元素； 修改数据同样根据index索引查找修改； 删除数据的时候效率低，因为是连续的内存空间，除删除最后一个元素外，删除任一元素都会使数组中的元素进行移动； 查找数据可根据index索引快速查找；
2. ``LinkedList``是基于链表的数据结构 对比以上： 优点： 不需要考虑扩容的问题和连续的内存空间问题，在新增和删除的效率更好 缺点： 缺少了索引，降低了查找元素的效率，对应也降低了修改元素的效率

### Map

![alt text](image-43.png)

```java
// 为了更好理解各类的关系，下面附上：各类的定义图
// HashMap 
public class HashMap<K,V> 
    extends AbstractMap<K,V> 
    implements Map<K,V>, Cloneable, Serializable{} 
 
// LinkedHashMap 
public class LinkedHashMap<K,V> 
    extends HashMap<K,V> 
    implements Map<K,V>{}

// TreeMap 
public class TreeMap<K,V> 
    extends AbstractMap<K,V> 
    implements NavigableMap<K,V>, Cloneable, java.io.Serializable{} 

// Hashtable 
public class Hashtable<K,V> 
    extends Dictionary<K,V> 
    implements Map<K,V>, Cloneable, java.io.Serializable {} 

// ConcurrentHashMap 
public class ConcurrentHashMap<K, V> extends AbstractMap<K, V> 
        implements ConcurrentMap<K, V>, Serializable {} 
```

#### HashMap 与 LinkedHashMap、TreeMap的区别

![alt text](image-44.png)

1. ``HashMap``不保证数据有序
2. ``LinkedHashMap``保证数据可以保持插入顺序
3. ``TreeMap``可以保持key的大小顺序

#### HashMap 与 Hashtable 的区别

![alt text](image-47.png)

1. ``HashMap`` 是非 ``synchronized`` 的，性能更好
2. ``HashMap`` 可以接受为 ``null`` 的 key-value，而``Hashtable`` 是线程安全的，比 ``HashMap`` 要慢，不接受 ``null`` 的 key-value

#### HashMap 与 ConcurrentHashMap 的区别

![alt text](image-45.png)

#### HashCode作用

![alt text](image-46.png)

#### HashMap 1.7

[HashMap](https://blog.csdn.net/carson_ho/article/details/79373026)

![alt text](image-51.png)

![alt text](image-52.png)

##### 基本概念

**容量（capacity）**： HashMap中数组的长度
**加载因子(Load factor)**：HashMap在其容量自动增加前可达到多满的一种尺度
![alt text](image-54.png)
**扩容阈值（threshold）**：当哈希表的大小 ≥ 扩容阈值时，就会扩容哈希表（即扩充HashMap的容量）

> **扩容阈值 = 容量 x 加载因子**

##### 存储流程

![alt text](image-53.png)

> 即 HashMap的本质 = 1个存储Entry类对象的数组 + 多个单链表
Entry对象本质 = 1个映射（键 - 值对），属性包括：键（key）、值（value） & 下1节点( next) = 单链表的指针 = 也是一个Entry对象，用于解决hash冲突

真正初始化哈希表（初始化存储数组table）是在第1次添加键值对时，即第1次调用put（）时。下面会详细说明

![alt text](image-55.png)

- 当 key ==null时，将该 key-value 的存储位置规定为数组table 中的第1个位置，即table [0]

计算下标位置流程

![alt text](image-56.png)

> 所有处理的根本目的，都是为了提高 存储key-value的数组下标位置 的随机性 & 分布均匀性，尽量避免出现hash值冲突。即：对于不同key，存储的数组下标位置要尽可能不一样

##### 为什么不直接采用经过hashCode（）处理的哈希码 作为 存储数组table的下标位置？

结论：容易出现 哈希码 与 数组大小范围不匹配的情况，即 计算出来的哈希码可能 不在数组大小范围内，从而导致无法匹配存储位置

![alt text](image-57.png)

##### 为什么采用 哈希码 与运算(&) （数组长度-1） 计算数组下标？

结论：根据HashMap的容量大小（数组长度），按需取 哈希码一定数量的低位 作为存储的数组下标位置，从而 解决 “哈希码与数组大小范围不匹配” 的问题

![alt text](image-58.png)

##### 为什么在计算数组下标前，需对哈希码进行二次处理：扰动处理？

结论：加大哈希码低位的随机性，使得分布更均匀，从而提高对应数组存储下标位置的随机性 & 均匀性，最终减少Hash冲突

![alt text](image-59.png)

##### 扩容机制

![alt text](image-60.png)

##### 总结

![alt text](image-61.png)

#### HashMap 1.8

![alt text](image-62.png)

![alt text](image-64.png)

![alt text](image-63.png)

![alt text](image-65.png)

##### 扩容机制

![alt text](image-66.png)

![alt text](image-67.png)

![alt text](image-68.png)

#### 哈希表如何解决Hash冲突

![alt text](image-69.png)

#### 为什么HashMap具备下述特点：键-值（key-value）都允许为空、线程不安全、不保证有序、存储位置随时间变化

![alt text](image-70.png)

#### 为什么 HashMap 中 String、Integer 这样的包装类适合作为 key 键

![alt text](image-71.png)

#### HashMap 中的 key若 Object类型， 则需实现哪些方法？

![alt text](image-72.png)

### 阻塞队列

![alt text](image-81.png)

### Array/Linked

![alt text](image-82.png)

## 多线程

### 创建线程的方式有哪些？

![alt text](image-48.png)

1. 继承``Thread``类，重写``run``方法
2. 实现``Runnable``接口，并实现该接口的``run``方法
3. 实现``Callable``接口，重写``call``方法
4. 使用线程池

### 线程的状态有哪些？

1. New:新创建状态。线程被创建，还没有调用start方法
2. Runnable: 可运行状态。调用starth后进入当前状态
3. Blocked: 阻塞状态
4. Waiting: 等待状态
5. Timed waiting: 超时等待状态
6. Terminated: 终止状态

### 如何保证线程安全

当多个线程要共享一个实例对象的值得时候，那么在考虑安全的多线程并发编程时就要保证下面3个要素：

1. 原子性（Synchronized, Lock）
2. 有序性(Volatile，Synchronized, Lock)
3. 可见性(Volatile，Synchronized,Lock)

由于``synchronized``和``Lock``保证每个时刻只有一个线程执行同步代码，所以是线程安全的，也可以实现这一功能，但是由于线程是同步执行的，所以会影响效率。

- 原子性： 指的是一个或多个操作要么全部执行成功要么全部执行失败。
- 可见性： 指当多个线程访问同一个变量时，一个线程修改了这个变量的值，其他线程能够立即看得到修改的值。
- 有序性：程序执行的顺序按照代码的先后顺序执行。（处理器可能会对指令进行重排序）

### ThreadPool

![alt text](image-49.png)

![alt text](image-50.png)

![alt text](image-73.png)

### ThreadLocal

![alt text](image-74.png)

ThreadLocal用于保存某个线程共享变量：对于同一个``static ThreadLocal``，不同线程只能从中get，set，remove自己的变量，而不会影响其他线程的变量。

1. ThreadLocal.get: 获取ThreadLocal中当前线程共享变量的值。
2. ThreadLocal.set: 设置ThreadLocal中当前线程共享变量的值。
3. ThreadLocal.remove: 移除ThreadLocal中当前线程共享变量的值。
4. ThreadLocal.initialValue: ThreadLocal没有被当前线程赋值时或当前线程刚调用remove方法后调用get方法，返回此方法值。

核心原理

- ThreadLocal类中有1个Map（称：ThreadLocalMap）：用于存储每个线程 & 该线程设置的存储在ThreadLocal变量的值
- ThreadLocalMap的键Key = 当前ThreadLocal实例、值value = 该线程设置的存储在ThreadLocal变量的值
- 该key是 ThreadLocal对象的弱引用；当要抛弃掉ThreadLocal对象时，垃圾收集器会忽略该 key的引用而清理掉ThreadLocal对象

#### ThreadLocal如何做到线程安全

1. 每个线程拥有自己独立的ThreadLocals变量（指向ThreadLocalMap对象 ）
2. 每当线程 访问 ThreadLocals变量时，访问的都是各自线程自己的ThreadLocalMap变量（键 - 值）
3. ThreadLocalMap变量的键 key = 唯一 = 当前ThreadLocal实例

#### 与同步机制区别

![alt text](image-75.png)

### 什么是悲观锁和乐观锁？

- 乐观锁：默认为，某个线程在自己处理共享资源的时候，不会出现同一时刻来修改此资源的前提，只在处理完毕，最后写入内存的时候，检测是否此资源在之前未被修改。类似于读写锁的读锁就是乐观锁。
- 悲观锁：默认为，某个线程在自己处理共享资源的时候，一定会出现同一时刻来修改此资源，所以刚拿到这个资源就直接加锁，不让其他线程来操作，加锁在逻辑处理之前。类似，``synchronized``关键字，条件锁，数据库的行锁，表锁等就是悲观锁。

### synchronized

非公平锁
![alt text](image-76.png)

### Lock、ReentrantLock

公平锁, 等待可中断
![alt text](image-77.png)

### synchronized 与 Lock

![alt text](image-78.png)

### synchronized 和 volatile 关键字的区别

1. ``volatile``本质是在告诉jvm当前变量在寄存器（工作内存）中的值是不确定的，需要从主存中读取；
2. ``synchronized``则是锁定当前变量，只有当前线程可以访问该变量，其他线程被阻塞住。
3. ``volatile``仅能使用在变量级别
4. ``synchronized``则可以使用在变量、方法、和类级别的
5. ``volatile``仅能实现变量的修改可见性，不能保证原子性；而``synchronized``则可以保证变量的修改可见性和原子性
6. ``volatile``不会造成线程的阻塞；``synchronized``可能会造成线程的阻塞。
7. ``volatile``标记的变量不会被编译器优化；``synchronized``标记的变量可以被编译器优化

### 谈一谈线程 sleep() 和 wait() 方法的区别？

1. ``sleep`` 是``Thread``类的方法，``wait``是``Object``类的方法
2. ``sleep``不释放锁，``wait``释放锁
3. ``sleep``不需要``Synchronized`` ，``wait``需要``Synchronized``
4. ``sleep``不需要唤醒，``wait``需要唤醒（除wait(int time)）

### 谈谈 Java 线程中 notify 和 notifyAll 方法有什么区别

- notify：只会唤醒等待该锁的其中一个线程。
- notifyAll：唤醒等待该锁的所有线程。

既然notify会唤醒一个线程，并获取锁，notifyAll会唤醒所有线程并根据算法选取其中一个线程获取锁

### Java 中有哪些常见的锁

1. synchronized
2. ReentrantLock
3. ReentrantReadWriteLock
4. AtomicInteger

## JVM

![alt text](image-83.png)

### 内存分区

![alt text](image-84.png)

#### 堆内存

![alt text](image-85.png)

#### 栈内存

![alt text](image-86.png)

#### 本地方法栈

十分类似Java虚拟机栈，与Java虚拟机区别在于：服务对象，即
Java虚拟机栈为执行 Java 方法服务；本地方法栈为执行 ``Native``方法服务

#### 静态方法区

![alt text](image-87.png)

#### 程序计数器

![alt text](image-88.png)

#### 总结

![alt text](image-89.png)

### 对象创建

![alt text](image-90.png)

虚拟机将为对象分配内存，即把一块确定大小的内存从 Java 堆中划分出来
对象所需内存的大小在类加载完成后便可完全确定

关于分配内存，此处主要讲解内存分配方式

内存分配 根据 Java堆内存是否绝对规整 分为两种方式：**指针碰撞 & 空闲列表**

Java堆内存 规整：已使用的内存在一边，未使用内存在另一边
Java堆内存 不规整：已使用的内存和未使用内存相互交错

![alt text](image-91.png)

#### 指针碰撞

假设Java堆内存绝对规整，内存分配将采用指针碰撞

分配形式：已使用内存在一边，未使用内存在另一边，中间放一个作为分界点的指示器

![alt text](image-92.png)

#### 空闲列表

假设Java堆内存不规整，内存分配将采用 空闲列表

分配形式：虚拟机维护着一个 记录可用内存块 的列表，在分配时从列表中找到一块足够大的空间划分给对象实例，并更新列表上的记录

### 对象内存布局

![alt text](image-93.png)

### 对象的访问方式

![alt text](image-94.png)

### 对象存活判断

![alt text](image-95.png)

### 垃圾回收

![alt text](image-96.png)

#### 复制

![alt text](image-100.png)

不 按 ``1：1的比例`` 划分内存，而是 按``8：1：1``比例 将内存划分为一块较大的 Eden 和两块较小的 Survivor 区域（From Survivor、To Survivor）

![alt text](image-101.png)

1. 每次使用Eden、From Survivor区域；
2. 用完后就 将上述两块区域存活的对象 复制到To Survivor区域上
3. 最终一次清理掉Eden、From Survivor区域

### 垃圾回收期器

[参见](https://carsonho.blog.csdn.net/article/details/102675617)

![alt text](image-102.png)

#### 标记整理

![alt text](image-97.png)

#### 分代收集

![alt text](image-98.png)
![alt text](image-99.png)

### 类加载过程

![alt text](image-103.png)

![alt text](image-104.png)

### 类加载器

[参见](https://carsonho.blog.csdn.net/article/details/103021610)

1. 实现类加载的功能
2. 确定被加载类 在 Java虚拟机中 的 **唯一性**

> 确定 两个类是否 相等 的依据：是否由同一个类加载器加载
若 **由同一个类加载器** 加载，则这两个类相等；
若 **由不同的类加载器** 加载，则这两个类不相等。

![alt text](image-105.png)

### 双亲委派模型

![alt text](image-106.png)

步骤总结：若一个类加载器收到了类加载请求

把 **该类加载请求** 委派给 **父类加载器**去完成，而不会自己去加载该类
每层的类加载器都是如此，因此所有的加载请求最终都应传送到顶层的启动类加载器中

只有当 **父类加载器** 反馈 自己无法完成该加载请求（它的搜索范围中没有找到所需的类）时，子加载器才会自己去加载

Java类随着它的类加载器一起具备了一种带优先级的层次关系

> 如：类 java.lang.Object（存放在rt.jar中）在加载过程中，无论哪一个类加载器要加载这个类，最终需委派给模型顶端的启动类加载器进行加载，因此Object类在程序的各种类加载器环境中都是同一个类。
>若没有使用双亲委派模型（即由各个类加载器自行去加载）、用户编写了一个java.lang.Object的类(放在ClassPath中），那系统中将出现多个不同的Object类，Java体系中最基础的行为就无法保证.

### 方法分派

![alt text](image-107.png)

## Others

### Java 中有几种类型的流

字节流和字符流。字节流继承于 ``InputStream`` 和 ``OutputStream``，字符流继承于 ``InputStreamReader`` 和 ``OutputStreamWriter``。

### xml 解析方式

![alt text](image-35.png)

### Serializable 和 Parcelable 区别

1. ``Serializable`` 是Java本身就支持的接口。
2. ``Parcelable`` 是Android特有的接口，效率比实现``Serializable``接口高效(可用于Intent数据传递，也可以用于进程间通信(IPC))。
3. ``Serializable``的实现，只需要``implements Serializable``即可。这只是给对象打了一个标记，系统会自动将其序列化。
4. ``Parcelabel``的实现，不仅需要``implements Parcelabel``，还需要在类中添加一个静态成员变量``CREATOR``，这个变量需要实现 ``Parcelable.Creator``接口。
5. ``Serializable`` 使用I/O读写存储在硬盘上，而``Parcelable``是直接在内存中读写。
6. ``Serializable`` 会使用反射，序列化和反序列化过程需要大量I/O操作，``Parcelable`` 自己实现封送和解封操作不需要用反射，数据也存放在Native内存中，效率要快很多

### Java 中深拷贝与浅拷贝的区别？

1. 浅拷贝：对基本数据类型进行值传递，对引用数据类型进行引用传递般的拷贝，此为浅拷贝。(改指针引用)
2. 深拷贝：对基本数据类型进行值传递，对引用数据类型，创建一个新的对象，并复制其内容，此为深拷贝。(复制一份存下来)

### 生产者消费者问题

![alt text](image-36.png)

[代码参见](https://carsonho.blog.csdn.net/article/details/121468054)

### 泛型

1. 泛型是对Java语言类型系统的一种扩展，可以把类型参数看作是使用参数化类型时指定的类型的一个占位符，引入泛型，是对Java语言一个较大的功能增强，带来了很多的好处。
2. 类型安全。类型错误现在在编译期间就被捕获到了，而不是在运行时当作java.lang.ClassCastException展示出来，将类型检查从运行时挪到编译时有助于开发者更容易找到错误，并提高程序的可靠性。
3. 消除了代码中许多的强制类型转换，增强了代码的可读性，为较大的优化带来了可能。

### 反射

[详见](https://carsonho.blog.csdn.net/article/details/80921333)

### 什么时候用断言（assert）

- 断言在软件开发中是一种常用的调试方式
- 断言检查通常在开发和测试时开启,发布时关闭
- 断言是一个包含布尔表达式的语句，在执行这个语句时假定该表达式为true；如果表达式的值为false，那么系统会报告一个AssertionError。断言的使用如下面的代码所示：assert(a > 0); // throws an AssertionError if a <= 0
- Android中不推荐使用断言

### Java中的四种引用及应用场景

Java中的引用有四种：强引用，弱引用，软引用，虚引用

![alt text](image-23.png)

- **强引用**: 通常我们使用new操作符创建一个对象时所返回的引用即为强引用
- **软引用**: 若一个对象只能通过软引用到达，那么这个对象在内存不足时会被回收，可用于图片缓存中，内存不足时系统会自动回收不再使用的Bitmap
- **弱引用**: 若一个对象只能通过弱引用到达，那么它就会被回收（即使内存充足），同样可用于图片缓存中，这时候只要Bitmap不再使用就会被回收
- **虚引用**: 虚引用是Java中最“弱”的引用，通过它甚至无法获取被引用的对象，它存在的唯一作用就是当它指向的对象回收时，它本身会被加入到引用队列中，这样我们可以知道它指向的对象何时被销毁

### 并发和并行的区别

- **并发**：（在一个时间段内同时执行多件事）如单核cpu以时间片的方式让多个线程轮循执行，在外界看来他们是同时执行的
- **并行**：（在一个时刻同时执行多件事）多核cpu每个核运行一个App，他们是真正的同时执行

### 字节流和字符流的区别

- 字节流操作的基本单元是字节；字符流是Unicode字符
- 字节流不使用缓冲区，字符流使用缓冲区
- 字节流通常用于处理二进制数据，实际上它可以处理任意类型的数据，但它不支持直接写入或读取Unicode码元；字符流通常处理文本数据，它支持写入及读取Unicode码元。

### IO和NIO区别

- IO面向流，NIO面向缓冲区
- IO是阻塞的，NIO是非阻塞的
- Java NIO的选择器允许一个单独的线程来监视多个输入通道，你可以注册多个通道使用一个选择器，然后使用一个单独的线程来“选择”通道：这些通道里已经有可以处理的输入，或者选择已准备写入的通道。这种选择机制，使得一个单独的线程很容易来管理多个通道

![alt text](image-79.png)

### JNI 与 NDK

![alt text](image-80.png)

### 大文件的复制

利用NewIO的FileChannel

### 如何在Java中创建Immutable对象

- 私有化成员变量
- 通过构造方法初始化成员变量
- 只提供get方法，不提供set方法
- get方法返回的是一个拷贝副本

### for-each与常规for循环的效率对比

for-each 使代码更加简洁优雅
for-each 实际上是通过迭代器（Iterator）实现的

### Comparable和Comparator接口是干什么的

他们都是接口

- Comparable是比较本实例和其他实例的大小
- Comparator是比较器，用来输入两个实例后比较两个实例大小

### 用最有效率的方法计算2乘以8？

2 << 3（左移n位相当于乘以2的n次方，右移n位相当于除以2的n次方）。

### 请说说对HashMap的理解

1. HashMap是基于Map接口的实现，存储键值对时，它可以接收null的键值，是非同步的，
HashMap存储着Entry(hash, key, value, next)对象
（2）通过hash的方法，通过put和get存储和获取对象。存储对象时，我们将K/V传给put
方法时，它调用hashCode计算hash从而得到bucket位置，进一步存储，HashMap会根据当前bucket的占用情况自动调整容量(超过 Load Facotr 则resize为原来的
2倍)。获取对象时，我们将K传给get，它调用hashCode计算hash从而得到bucket
位置，并进一步调用equals()方法确定键值对。如果发生碰撞的时候，Hashmap通
过链表将产生碰撞冲突的元素组织起来，在Java 8中，如果一个bucket中碰撞冲突
的元素超过某个限制(默认是8)，则使用红黑树来替换链表，从而提高速度
（3）通过对key的hashCode()进行hashing，并计算下标( (n-1) & hash )，从而获得
buckets的位置。如果产生碰撞，则利用key.equals()方法去链表或树中去查找对应
的节点
（4）在Java 1.8的实现中，是通过hashCode()的高16位异或低16位实现的： (h =
k.hashCode()) ^ (h >>> 16) ，主要是从速度、功效、质量来考虑的，这么做
可以在bucket的n比较小的时候，也能保证考虑到高低bit都参与到hash的计算中，
同时不会有太大的开销。
（5）如果超过了负载因子(默认0.75)，则会重新resize一个原来长度两倍的HashMap，
并且重新调用hash方法。
