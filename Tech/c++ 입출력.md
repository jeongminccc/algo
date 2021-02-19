# sync_with_stdio()

C++ 같은 경우 기본적으로 C를 품고 구현되어졌다. 따라서, C와 거의 완벽(?) 한 호환을 이뤄야한다는 점이 중요했다. 이런점에서 입출력 같은 경우 C와 C++이 호환적으로 이뤄져야했는데, stream을 이중으로 유지해 입력과 출력 스트림을 따로 유지했다. 즉, C 스트림과 C++ 스트림이 따로 유지가 되었고, 개행 문자를 통해 구별하는 입출력인 printf와 같은 것은 C 스트림 그리고 cout, cin 과 같은 객체를 이용한 입출력은 C++ 스트림으로 구별되었다. 그리고 출력하기 전에 동기화를 맞춰 출력하도록 했다.

```cpp
#include <iostream>
#include <cstdio>

int main()
{
    cout << "haha";
    printf("%s\n",hoho);
}
```

위와 같이 출력을 해도 잘 출력이 되는 것을 볼 수 있다. 즉, stream은 달리 들어가지만, 출력 시 동기화를 맞춰 출력을 하도록 내부적으로 구현되어져 있기 때문이다. 동기화를 잘 유지하기 위해 thread-safe하게 동작한다. 이런 동작은 이용은 편리하지만, 속도를 저하시킨다 는 문제가 존재한다.  

생각해보면, 동기화를 위해 thread간 순서를 유지하는 동작은 정말 큰 overhead이다. 그렇다면 이 동작들을 하지 않는다면(?) 속도는 월등하게 상승할 수 있다.  

- ios_base::sync_with_stdio(false);  

위의 문법과 같이, 입출력의 sync를 맞추지 않겠다고 C++에서 명령한다면, C++ 자체는 “아.. 이제 C stream에 대해 관리할 필요가 없구나를 생각한다. “ 즉, C++ 자체 버퍼만 이용하면 되는구나. thread 동기화를 생각할 필요 없구나 생각하게 된다. 위와같이 설정을 하게 된다면, stream 관리가 필요 없고 독립적인 stream 버퍼만 운영하기 때문에 입출력에서는 속도 향상을 시킬 수 있다.  

다만, 주의해할 점이 있다. 앞서 말했듯, stream을 C++ 기준으로만 하기 때문에 C언어 관련 입출력연산(scanf/printf/puts/getchar/putchar 등)들을 사용하지 못한다. 이 부분을 꼭 기억해야한다.  

# cin.tie()  

cin 과 cout은 tie() 즉, 묶여있다. tie() 동작은 std::cin 통해 입력을 받기전에 std::cout을 flushing 하도록 한다. tie() 동작은 상호작용을 요하는 console 프로그램에서 유용하지만, large I/O 동작을 할 때 속력이 느려지는 단점이 있다. 만약 아래의 코드와 같이, Null을 인자로 전달하게 된다면, utie 동작을 수행할 수 있다.  

- cin.tie(NULL);  

위의 코드를 사용하면, 단점인, 다수의 데이터가 들어올 경우 속도가 빨라질 수 있다. 백준 문제를 생각해보면, 지속적으로 출력을 하는 것이 아닌 결과를 모아서 한번에 출력하면 되도록 되어져있다. 따라서, tie() 동작을 굳이 할필요가 없으며, tie() 동작을 제거하고 flushing을 제거하게 된다면 속도가 빨라질 수 있다.  

아래의 예시를 보자.  

```cpp#include <iostream>
int main()
{
    std::cout << "Enter name:";
    std::cin >> name;
}
```
output

```cpp
#include <iostream>
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    std::cout << "Enter name:";
    std::cin >> name;
}
```
> 출처 : https://nerdooit.github.io/2020/06/20/cpp_fastio.html
