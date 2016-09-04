
介绍
---
制作自己的工具类库。临近毕业，将自己所学的知识，常用的数据结构，排序算法，查找算法，Hash算法等等一系列的算法的实现生成一个自己的库。虽然目前有很多已经实现的库, 有人可能会说不需要重复的建造轮子,但是我想说的是我们应该具有建造轮子的能力。考虑的未来，别人的“轮子"不一定就比自己的”轮子“效率高。


代码组织目录
---

	----tools （根目录)
			|-----------sort (排序算法模块)
			|			|----------src
			|			|			|----------sort.hpp (代码实现)
			|			|			|
			|			|			|----------sortdef.h(宏或其他)
			|			|
			|----------search(搜索算法模块)
			|			|----------src
			|			|			|----------search.hpp
			|			|			|
			|			|			|----------searchdef.h 
			|			|			|
			|-----------hash (hash算法)
			|			|----------src
			|			|			|----------hash.hpp 
			|			|			|
			|			|			|----------hashdef.h 
			|			|			|
			|----------tree (tree算法)
			|			|----------src
			|			|			|----------tree.hpp
			|			|			|
			|			|			|----------tree.h


代码编译框架
---



LCIENCE
---
CUG@2016 SUN-HE