//
//  vector 메모리 해제.cpp
//  algo
//
//  Created by jm on 2020/09/03.
//  Copyright © 2020 jm. All rights reserved.
//
#include <iostream>
#include <vector>

int main ()
{
  std::vector<int> myvector (100);
  std::cout << "1. capacity of myvector: " << myvector.capacity() << '\n';

  myvector.resize(10);
  std::cout << "2. capacity of myvector: " << myvector.capacity() << '\n';

  myvector.shrink_to_fit();
  std::cout << "3. capacity of myvector: " << myvector.capacity() << '\n';

    std::vector<int> myvector2 (100);
    std::cout << "1. capacity of myvector: " << myvector2.capacity() << '\n';

    myvector2.erase(myvector2.begin(), myvector2.begin() + 10);
    std::cout << "2. capacity of myvector: " << myvector2.capacity() << '\n';

    myvector2.shrink_to_fit();
    std::cout << "3. capacity of myvector: " << myvector2.capacity() << '\n';
    
    std::vector<int> myvector3 (100);
    std::cout << "1. capacity of myvector: " << myvector3.capacity() << '\n';

    myvector3.clear();
    std::cout << "2. capacity of myvector: " << myvector3.capacity() << '\n';

    myvector3.shrink_to_fit();
    std::cout << "3. capacity of myvector: " << myvector3.capacity() << '\n';

    return 0;
}
