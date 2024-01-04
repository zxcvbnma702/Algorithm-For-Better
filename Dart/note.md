# Dart

## 变量与方法

### 变量

1. Dart 可以显示指明类型来声明一个可变的变量。且指明的类型分为可空和非空
2. Dart 也可以使用 ``var`` 关键字来声明一个可变的变量，此时编译器会根据变量初始值自动推断类型
3. Dart 使用 ``final`` 关键字来声明一个不可变的变量，且可以替代 ``var`` 或加在类型前面
4. Dart 中变量如果是非空类型，那么必须给一个默认值，否则无法编译通过。如果是可空类型，默认值都为 ``null``
5. Dart 中每一行代码都要加 ``;``

```dart
//1、Dart 可以显示指明类型来声明一个可变的变量。且指明的类型分为可空和非空
//1.1、类比 Java，显示指明类型来声明一个可变的变量
//dart 写法：
int a = 10;
bool b = true;
​
//Java 写法
int a = 10;
boolean b = true;
​
//1.2、指明的类型分为可空和非空
//dart 写法
int? a = 10;
bool? b = true;
​
//kotlin 写法
var a: Int? = 10
var b: Boolean? = true
  
//2、Dart 也可以使用 var 关键字来声明一个可变的变量，此时编译器会根据变量初始值自动推断类型
//dart 写法
var a = 10;
var b = true;
​
//kotlin 写法
var a = 10
var b = true
  
//3、Dart 使用 final 关键字来声明一个不可变的变量，且可以替代 var 或加在类型前面
//dart 写法
final a = 10;
final int aa = 10;
final b = true;
final bool bb = true;
​
//Java 写法
final int a = 10;
final boolean b = true;
​
//5、Dart 中变量如果是非空类型，那么必须给一个默认值。如果是可空类型，默认值都为 null
void main() {
  String s = "erdai";
  int? i;
  print('$s $i'); //打印结果：erdai null
}
```

> Dart 完全抛弃了 Java 中的基本数据类型，全部都是对象数据类型

6. Dart 中还可以使用 Object 和 dynamic 关键字来声明一个变量

```dart
//1、Dart 中还可以使用 Object 和 dynamic 关键字来声明一个变量
//1.1、Object 声明变量，这一点和 Java 没任何区别
Object a = 10;
Object b = true;
Object str = "erdai666";
​
//1.2、dynamic 声明变量，这一点是 Java 所没有的
dynamic a = 10;
dynamic b = true;
dynamic str = "erdai666";

//1、声明一个 Object 类型的变量调用 substring，此时会编译报错，因为 Object 没有 substring 方法
Object str = "erdai666";
str.substring(1); //编译报错：The method 'substring' isn't defined for the type 'Object'.
​
//2、使用 dynamic 定义一个变量调用 substring，此时可以绕过编译检查
dynamic str = "erdai666";
str.substring(1);
```

### 常量

1. Dart 使用 ``const`` 关键字来定义一个常量
2. Dart 可以使用 ``const`` 关键字替代 ``var`` 或加在类型前面
3. Dart 还可以使用 ``const`` 关键字来创建一个常量

```dart
//1、Dart 使用 const 关键字来定义一个常量
//2、Dart 可以使用 const 关键字替代 var 或加在类型前面
const a = 10;
const b = true;
const int aa = 10;
const bool bb = true;
​
//3、Dart 还可以使用 const 关键字来创建一个常量
//创建一个内容和引用都不可变的 list 数组
var list = const [1,2,3];
//创建一个内容和引用都不可变的 set 集合
var set = const {1,2,3};
```

#### final 与 const 区别

1. ``final`` 可以一开始不赋值，如果赋值了则不可变。``const`` 一开始就需要赋值且不可变
2. ``const`` 必须给一个明确的编译常量值（即编译期间就确定的值）
3. ``final`` 可以通过计算或者方法获取一个值（即运行期间确定的值）
4. ``final`` 表示引用不可变，但内容是可变的。``const`` 表示内容和引用都不可变

```dart
//1、final 可以一开始不赋值，如果赋值了则不可变。const 一开始就需要赋值且不可变
//2、const 必须给一个明确的编译常量值（即编译期间就确定的值）
//3、final 可以通过计算/方法获取一个值（即运行期间确定的值）
​
final a;//编译通过
a = 10;//编译通过
​
const b;//编译报错
b = 10;//编译报错
​
//4、final 表示引用不可变，但内容是可变的。const 表示内容和引用都不可变
final set = {1,2,3};
set.add(4);
​
var list = const [1,2,3];
list.add(4);//运行报错，const list 不可新增元素
```

### 方法

- 所有方法都有返回值，即使返回值是 void
- 方法的返回类型，可写可不写。如果不写，会根据方法体里面最后一行代码进行类型推断
- 如果没有写返回类型，且方法体最后一行代码没有明确写返回语句，那么默认执行：return null
- 方法名称可以随便取，就像 Java ，Kotlin 里面定义方法名一样
- 方法名里面的参数可以有任意多个，参数的声明格式有两种：``var 参数名`` ``类型 参数名``
- 如果方法体只有一行表达式，可将其改成单行方法样式，方法名和方法体用 => 连接

```dart
//1、Dart 写法1：方法的参数使用：var 参数名
String methodName(var name,var age){
  return "erdai666";
}
​
//2、Dart 写法2：方法的参数使用：类型 参数名
String methodName(String name,int age){
  return "erdai666";
}
​
//3、Dart 写法3：方法的返回类型可省略，根据方法体最后一行代码进行返回类型推断
methodName(var name,var age){
  return "erdai666";
}
​
//4、如果没有写返回类型，且方法体最后一行代码没有明确写返回语句，那么默认执行：return null
methodName(var name,var age){
  
}
​
//5、Dart 写法4：无返回值使用 void 关键字
void methodName(var name,var age){
  
}
​
//6、Dart 写法5：如果方法体只有一行表达式，可将其改成单行方法样式，方法名和方法体用 => 连接
String methodName(var name,var age) => "erdai666";
```

#### 可选参数 & 命名参数 & 默认参数

可选参数顾名思义就是可以选择的参数，使用 ``[]`` 表示可选的位置参数，如下：

```dart
void optionFunction(var value1,[var value2 = 2,var value3 = 3]){
  print('$value1 $value2 $value3');
}
​
void main(){
  optionFunction(1);
}
​
//打印结果
1 2 3
```

1. 命名参数默认都为可选参数。如果是必要参数，则需要用 ``required`` 关键字，且使用 ``required`` 修饰的参数不能提供默认值
2. 使用 ``{}`` 来指定命名参数
3. 命名参数必须以 `key: value` 的形式去指定

```dart
//1、使用 {} 来指定命名参数
void optionFunction(var value1,{var value2 = 2,var value3 = 3}){
  print('$value1 $value2 $value3');
}
​
void main(){
  optionFunction(1,value3: 4);
}
//打印结果
1 2 4
​
 
//2、如果是必要参数，则需要用 required 关键字，且使用 required 修饰的参数不能提供默认值
//此时 value2 为必传的参数
void optionFunction(var value1,{required var value2,var value3 = 3}){
  print('$value1 $value2 $value3');
}  
​
void main(){
  optionFunction(1,value2: 4);
}
//打印结果
1 4 3
```

1. 默认参数就是给可选参数提供默认值，以便在未提供相应实参时使用
2. 默认值必须是编译时常量
3. 如果可选参数没有提供默认值，那默认值就为 null

#### 匿名方法（又称闭包）

匿名方法顾名思义就是没有名字的方法，语法规则如下：

```dart
//1、方式一：
(var 参数名){
   方法体
}
​
//2、方式二：
(类型 参数名){
   方法体
}
​
//3、方式三：如果方法体只有一行代码可以将匿名方法用单行表示
(var 参数名) => 方法体
(类型 参数名) => 方法体
  
//4、方式四：省略 var 或类型
(参数名){
   方法体
}
​
(参数名) => 方法体
```

匿名方法一般会当做参数或赋值给一个变量

```dart
//1、匿名方法当作参数使用
void main(){
  const list = [1,2,3];
  list.forEach((element){
    print(element);
  });
  //可简化成如下写法：
  //list.forEach((element) => print(element));
}
​
//2、匿名方法赋值给一个变量
void main(){
  const list = [1,2,3];
  var function = (element){
    print(element);
  };
  //可简化成如下写法：
  //var function = (element) =>  print(element);
  list.forEach(function);
}
```

匿名方法立即执行

```dart
//1、方式1
void main(){
  var func = (){
    print('666');
  };
  (func)();
}
​
//2、方式2
void main(){
  ((){
    print('666');
  })();
}
​
//打印结果
666
```

匿名方法内部可以引用包含该匿名方法的所有层级作用域中的变量，与匿名方法调用的位置无关，如下：

```dart
//makeAdder 返回一个匿名方法
Function makeAdder(num addBy){
  //匿名方法访问 addBy 参数
  return (num i) => addBy + i;
}
​
void  main(){
  //创建一个匿名方法，传入实参为 2
  var add1 = makeAdder(2);
  //创建一个匿名方法，传入实参为 3
  var add2 = makeAdder(3);
​
  //分别调用两个匿名方法，并打印结果
  print(add1(3));
  print(add2(4));
}
​
//打印结果
5
7
```

#### 静态方法

使用 static 关键字修饰的方法即为静态方法，因静态方法不属于类实例，所以也无法访问类成员，静态方法可以使用类名直接调用

```dart
class Test{
  static String staticFunction1(){
    return "";
  }
​
  static void staticFunction2(){
 
  }
}
​
void main(){
  Test.staticFunction1();
  Test.staticFunction2();
}
```

## 类型与运算符

### 基本类型

#### 数字类型

1. 在dart语言中数字类型主要有下面三种：

> int：整数类型
> double：浮点数类型
> num：数字类型，int和double都是它的子类

```dart
var x = 1;   // 初始化为 int 类型
var y = 1.1;  // 包含小数，初始化为 double
​
// 明确指定数据类型
double z = 1;
num d = 100;
```

2. 数字类型和字符串类型互相转换

```dart
// 将 String 类型转换成 int 类型
var one = int.parse('1');
​
// 将 String 类型转换成 double 类型
var onePointOne = double.parse('1.1');
​
// 将 int 类型转换成 String 类型
String oneAsString = 1.toString();
​
// 将 double 类型转换成 String 类型, 保留两位小数
String piAsString = 3.14159.toStringAsFixed(2);
```

#### 字符串类型

1. 字符串类型使用单引号或者双引号包裹字符串都可以

```dart
var s1 = 'Hello';
var s2 = "erdai";
```

2. 字符串内嵌表达式

```dart
// 内嵌变量
var s3 = '你好: $s2';
​
// 内嵌表达式
var s4 = "转大写：${s2.toUpperCase()}";
```

3. 字符串相加（连接）

字符串相加，就是将两个字符串连接起来，dart 语言中有以下两种方式实现字符串连接：

- 连续的字面字符串定义，默认会将字符串连接起来
- 使用 + 加号连接字符串

```dar
void main(){
  //1、连续的字面字符串定义，默认会将字符串连接起来
  var str1 = "erdai" "666";
  //2、使用 + 加号连接字符串
  var str2 = "erdai" + "666";
  print(str1);
  print(str2);
}
​
//打印结果
erdai666
erdai666
```

4. 多行字符串定义

使用 ''' 三引号定义多行字符串，这种方式可以保留字符串的换行符

```dart
void main() {
  var s1 = '''
    这是第一行字符串。
    这是第二行字符串。
    ''';
  print(s1);
}
​
//打印结果
这是第一行字符串。
这是第二行字符串。
```

#### 布尔类型

布尔类型就两种值：true 或者 false， 分别表示真和假

```dart
var isOk = false;
bool status = true;
```

#### 枚举类型

1. 枚举类型其实就是一组常量的集合，都是只读的

```dart
// 使用 enum 关键字，定义 Color 枚举类型，Color 包含了3个常量 red、green、blue
enum Color { red, green, blue }
​
// 读取 Color.blue 枚举常量
var aColor = Color.blue;
​
// 使用 switch 语句判断 aColor 变量值
switch (aColor) {
  case Color.red:  // 使用枚举常量作为检测条件，aColor == Color.red 则成立。
    print('Red as roses!');
    break;
  case Color.green:
    print('Green as grass!');
    break;
  default: // 默认条件
    print(aColor); // 'Color.blue'
}
```

2. 枚举常量都有一个从 0 开始数字编号，第一个常量是 0，第二个是 1，以此类推

```dart
void main() {
  print(Color.green.index);
  print(Color.blue.index);
}
​
//打印结果
1
2
```

### 运算符

#### 级联运算符

级联调用就是通过 .. (两个连续的点) 连续调用对象的属性和方法

```dart
querySelector('#confirm') // 通过 querySelector 查询获得一个对象
  ..text = 'Confirm' // 设置对象 text 属性
  ..classes.add('important');  // 调用对象的 classes 属性的 add 函数
​
//等价如下代码
​
// 通过 querySelector 查询获得一个对象
var button = querySelector('#confirm');
// 设置对象 text 属性
button.text = 'Confirm';
// 调用对象的 classes 属性的 add 函数
button.classes.add('important');
```

#### 类型测试运算符

| 运算符 | 说明                                                                               |
| ------ | ---------------------------------------------------------------------------------- |
| as     | 用于类型转换，将一个对象类型转换成另外一种对象类型，一般用于子类对象转换成父类对象 |
| is     | 用于检测一个变量是否属于某种对象类型                                               |
| is!    | 用于检测一个变量不属于某种对象类型                                                 |

```dart
// 如果 emp 变量是 Person 类型则条件为 true
if (emp is Person) {
  // 忽略代码
}
​
// 永远返回 true, 因为所有类型都继承了 Object。
if (emp is Object) {
    // 忽略代码
}
```

#### 条件运算符

```dart
// 如果isPublic为真，visibility = 'public' 否则 visibility = 'private'
var visibility = isPublic ? 'public' : 'private';
​
// 这种语法在处理参数默认值非常有用。
// 如果name不等于null, 则payerName = name 否则payerName = 'Guest'
String payerName = name ?? 'Guest';
```

## 数组与集合

### List 数组

#### 定义

- 与 Java 的数组类型不同，Dart 中的数组类型就是 List，它是泛型类型数据结构，支持任意数据类型的数组
- List 数组定义的元素有序可重复，类似 Java 的 List 集合
- Dart 中 List 数组主要分为两种类型：
  可变长度数组
  固定长度数组
不管是哪种类型的数组，他们的操作方式是一样的

```dart
//1、可变长度数组
//定义一个 int 类型的可变数组
List<int> a = []; //等价：var a = <int>[];
​
//定义一个 String 类型的可变数组
var strs = <String>[]; //等价 List<String> strs = [];
​
//如下这种定义方式，编译器会给我们推断出是字符串类型的可变数组
var strs = ['字符串'];
```

- 熟悉 Java 的人都知道，上述这种定义就是泛型类型的语法，<> 符号定义的是 List 的元素类型
- 上述定义数组我们并没有指定数组大小，因此他们定义的都是可变数组，可变数组可以往数组中插入不限制数量的元素 （只要没超过内存限制）

```dart
//2、固定长度数组
//定义一个固定长度为 3 ，类型为 int 的数组
var list = List.filled(3,0);
​
//测试一
void main() {
  //定义一个固定长度为 3 ，类型为 int 的数组
  var list = List.filled(3,0);
  list[0] = 1;
  list[1] = 2;
  list[2] = 3;
  //此时如果我们添加第 4 个元素，则会报数组下标越界异常
  //list[3] = 4; //数组下标越界
  for (var value in list) {
    print(value);
  }
}
//打印结果
1
2
3
  
//测试二：
void main() {
  //定义一个固定长度为 2 ，类型为 String 的数组
  var list = List.filled(2,"");
  list[0] = "erdai";
  list[1] = "666";
​
  for (var value in list) {
    print(value);
  }
}
//打印结果
erdai
666
```

注意：

- 上述 filled 方法的两个参数：第一个表示数组长度，第二个表示存放的元素类型初始值
- 固定长度的数组，只能通过数组下标的方式读写数组，不能使用 add，insert 方法修改数组，否则会报错

#### 伸展运算符

如果我们想将一个 List 数组的元素填充到另外一个数组去，我们可以使用伸展运算符 ... ，如下：

```dart
var list = [1, 2, 3];
var list2 = [0, ...list]; // 将 list 数组的所有元素一个个展开来，插入到 list2 中
// 等价代码 var list2 = [0, 1, 2, 3]
```

#### 常用 Api 介绍

```dart
//1、首先定义一个 int 类型的可变数组
var a = <int>[];
​
//2、往数组尾巴添加元素 a:[1,2,3]
a.add(1);
a.add(2);
a.add(3);
​
//3、修改第一个元素的值 a:[0,2,3]
a[0] = 0;
​
//4、在数组 0 位置，插入 100 a:[100,0,2,3]
a.insert(0,100);
​
//5、删除一个元素 a:[100,0,2]
//根据元素删除
a.remove(3);
​
//根据下标删除 a:[100,2]
a.removeAt(1);
​
//6、获取数组大小
print(a.length); //打印：2
  
//7、数组排序：默认数组从小到大排序 a:[2,100]
a.sort();
​
//8、判断数组是否包含指定元素
a.contains(2); // true
​
//9、清空 List，删除所有数据 a:[]
a.clear();
```

### Set 集合

#### 定义

- Dart 中的 Set 是无序集合类型，Set 跟 List 都能保存一组数据，区别就是 Set 的元素都是唯一的，和 Java 的 Set 集合类似
- Set 支持任意类型数据，主要有下面三种方式初始化：

```dart
//1、方式一：使用 {} 定义一个 String 类型的 Set
var strSet = {"str"};
​
//2、方式二：定义一个空的 String 类型的 Set
var names = <String>{};
​
//3、方式三：通过 Set 对象定义一个可以保存 String 类型的 Set
var names = Set<String>();
```

#### 常用 Api 介绍

```dart
//1、首先定义一个 set 集合
var names = <String>{};
​
//2、添加一个元素 names:{"Dart"}
names.add("Dart");
​
//3、添加一个 List 数组 names:{"Dart","Flutter"}
var titles = ["Flutter"];
names.addAll(titles);
​
//4、获取 Set 大小
print(names.length); //打印：2
​
//5、删除元素
//根据元素进行删除 names:{"Dart"}
names.remove("Flutter");
​
//6、判断 Set 是否包含指定元素
names.contains("Dart"); //true
​
//7、清空 Set 所有元素 names:{}
names.clear();
```

### Map 集合

#### 定义

- Dart 中 map 类型，就是一种哈希类型数据，map 类型的数据都是由 key 和 value 两个值组成，key 是唯一的，value 不必唯一，读写数据都是通过 key 进行，map 也是泛型类型，支持任意类型数据，key 和 value 可以是任意类型数据
- map 主要有以下四种方式初始化：

```dart
//1、方式一：直接以key, value 的方式初始化一个 map 类型变量， key 和 value 都是 String 类型
var map1 = {
  //格式  Key: Value
  'first': 'partridge',
  'second': 'turtledoves',
  'fifth': 'golden rings'
};
​
//2、方式二：直接通过 Map 类构造一个 map 类型变量, key 类型为 String, value 类型为 int
var map2 = Map<String, int>();
​
//3、方式三：定义一个 key 类型为 String, value 类型为 int 的空 Map
var map3 = <String,int>{}
​
//4、方式四：定义一个绕过编译检查的动态 key，value 类型 Map
var map4 = Map(); //等价于：var map4 = {};
```

#### 常用 Api 介绍

```dart
//1、首先定义一个 map
var map = {};
​
//2、向 map 添加数据 map:{"key1":"value1","key2":"value2"}
//使用 [] 操作符读写 map 数据，语法：map变量[key]
map["key1"] = "value1";
map["key2"] = "value2";
​
//3、查询 map：使用[]操作符，根据 key 查询对应的 value 值，如果 key 不存在则返回 null
var v1 = map["key1"];
var v2 = map["key2"];
​
//4、更新 map 数据：根据 key 更新 map 数据和添加 map 数据用法一样
//如果 key 值不存在则添加，否则更新 key 的数据
//map:{"key1":"value1","key2":"value2"}
map["key2"] = "erdai";
​
//5、获取 map 大小
print(map.length); //打印：2
​
//6、遍历 map
map.forEach((k, v) {
  print('$k $v');
});
​
//7、删除 map 数据：通过 remove 函数可以删除指定的 key 数据
//map:{"key2":"value2"}
map.remove("key1");
​
//8、清空所有 map 数据 map:{}
map.clear();
```

## 面向对象编程

