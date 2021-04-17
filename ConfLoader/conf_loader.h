#ifndef __CONF_LOADER__
#define __CONF_LOADER__

#include <map>
#include <string>
#include <vector>

class ConfElement;
class ConfObject;
class ConfPrimitive;
class ConfArray;

class ConfElement {
	bool isObject;
	bool isPrimitive;
	bool isArray;
protected:
	ConfElement(bool isObject, bool isPrimitive, bool isArray);
public:
	bool IsObject();
	bool IsPrimitive();
	bool IsArray();
	ConfObject& GetAsObject();
	ConfPrimitive& GetAsPrimitive();
	ConfArray& GetAsArray();
};

class ConfObject : public ConfElement {
	std::map<std::string, ConfElement*> elements;
public:
	ConfObject();
	bool Contain(std::string name);
	ConfElement& Get(std::string name);
	ConfObject& GetAsObject(std::string name);
	ConfPrimitive& GetAsPrimitive(std::string name);
	ConfArray& GetAsArray(std::string name);
	void Add(std::string name, ConfElement* ele);
	~ConfObject();
};

class ConfArray : public ConfElement {
	std::vector<ConfElement*> elements;
public:
	ConfArray();
	int Size();
	ConfElement& Get(int index);
	ConfObject& GetAsObject(int index);
	ConfPrimitive& GetAsPrimitive(int index);
	ConfArray& GetAsArray(int index);
	void Add(ConfElement* ele);
	~ConfArray();
};

class ConfPrimitive : public ConfElement {
	std::string value;
public:
	ConfPrimitive();
	std::string Get();
	void Set(std::string value);
};

namespace ConfParser {
	ConfObject parse(std::string config);
}

#endif
