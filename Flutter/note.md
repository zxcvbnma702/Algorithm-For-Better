# Flutter开发问题

## 创建项目

### gradle镜像

gradle-wrapper.properties

```gradle
#distributionUrl=./gradle-7.5-all.zip
distributionUrl=https\://mirrors.cloud.tencent.com/gradle/gradle-7.5-all.zip
```

## UI

### svg转ttf

[iconmoon](https://icomoon.io/)

参考[文章](https://blog.csdn.net/hhbbeijing/article/details/124670408?utm_medium=distribute.pc_relevant.none-task-blog-2~default~baidujs_baidulandingword~default-1-124670408-blog-85258876.235^v43^pc_blog_bottom_relevance_base3&spm=1001.2101.3001.4242.2&utm_relevant_index=4)

### TextField

#### Flutter change focus color and icon color but not works

[solution](https://stackoverflow.com/questions/72871537/flutter-change-focus-color-and-icon-color-but-not-works)

### Theme

直接定义brightness.dark会报错, 所以使用如下写法

```dart
static final ThemeData darkTheme = ThemeData(
    colorScheme: ColorScheme.fromSwatch().copyWith(
        background: MyColor.black,
        brightness: Brightness.dark)
        );
```

### Button

#### 禁用按钮

    onPressed: _canFcous ? _handlePressed : () {},

### 倒计时实现

[倒计时](https://juejin.cn/post/6844903816114995207?searchId=20240206233140FAFD36055DFD3C58F7CE)

```dart
  late Timer _timer;
  int _countdownTime = 0;

  void startCountdownTimer() {
    const oneSec = Duration(seconds: 1);

    callback(timer) => {
          setState(() {
            if (_countdownTime < 1) {
              _timer.cancel();
              _buttonText = "提交";
              _canFcous = true;
            } else {
              _countdownTime = _countdownTime - 1;
              _buttonText = "Resend code in $_countdownTime s";
              _canFcous = false;
            }
          })
        };

    _timer = Timer.periodic(oneSec, callback);
  }

  void _handlePressed() {
    _otp = _fieldOne.text + _fieldTwo.text + _fieldThree.text + _fieldFour.text;
    if (_otp.isNum && _otp.length == 4) {
      widget.onChanged(_otp);
      _countdownTime = widget.countTime;
      startCountdownTimer();
    } else {
      widget.onChanged(MyVerifyCode.WrongMessage);
    }
  }
```