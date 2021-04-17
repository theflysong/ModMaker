#include "conf_loader.h"
#include <sstream>

ConfElement::ConfElement(bool isObject, bool isPrimitive, bool isArray) {
	this->isObject = isObject;
	this->isPrimitive = isPrimitive;
	this->isArray = isArray;
}

bool ConfElement::IsObject() {
	return isObject;
}

bool ConfElement::IsPrimitive() {
	return isPrimitive;
}

bool ConfElement::IsArray() {
	return isArray;
}

ConfObject& ConfElement::GetAsObject() {
	return *(ConfObject*)this;
}

ConfPrimitive& ConfElement::GetAsPrimitive() {
	return *(ConfPrimitive*)this;
}

ConfArray& ConfElement::GetAsArray() {
	return *(ConfArray*)this;
}

ConfObject::ConfObject() : ConfElement(true, false, false){
} 

bool ConfObject::Contain(std::string name) {
	return elements.count(name);
}

ConfElement& ConfObject::Get(std::string name) {
	return *(elements[name]);
}

ConfObject& ConfObject::GetAsObject(std::string name) {
	return Get(name).GetAsObject();
}

ConfPrimitive& ConfObject::GetAsPrimitive(std::string name) {
	return Get(name).GetAsPrimitive();
}

ConfPrimitive::ConfPrimitive(std::string value) : ConfElement(false, true, false){
	this->value = value;
}

ConfArray& ConfObject::GetAsArray(std::string name) {
	return Get(name).GetAsArray();
}

void ConfObject::Add(std::string name, ConfElement* ele) {
	elements[name] = ele;
}

ConfObject::~ConfObject() {
	for (auto e : elements) {
		delete e.second;
	}
}

ConfArray::ConfArray() : ConfElement(false, false, true) {
}

int ConfArray::Size() {
	return elements.size();
}

ConfElement& ConfArray::Get(int index) {
	return *(elements[index]);
}

ConfObject& ConfArray::GetAsObject(int index) {
	return Get(index).GetAsObject();
}

ConfPrimitive& ConfArray::GetAsPrimitive(int index) {
	return Get(index).GetAsPrimitive();
}

ConfArray& ConfArray::GetAsArray(int index) {
	return Get(index).GetAsArray();
}

void ConfArray::Add(ConfElement* ele) {
	elements.push_back(ele);
}

ConfArray::~ConfArray() {
	for (auto e : elements) {
		delete e;
	}
}

ConfPrimitive::ConfPrimitive() : ConfElement(false, true, false) {
}

std::string ConfPrimitive::Get() {
	return value;
}

void ConfPrimitive::Set(std::string value) {
	this->value = value;
}

namespace ConfParser {
	ConfArray* parseArray(std::istream& in) {
		using namespace std;
		ConfArray* arr = new ConfArray;
		string w;
		in >> w;
		if (w[0] == '{') {
			int i = 0;
			while (w[i] !='}') {
				i ++;
				string value = "";
				for (; i < w.length() ; i ++) {
					if(w[i] != ',' && w[i] != '}')
						value += w[i];
					else
						break;
				}
				arr->Add(new ConfPrimitive(value));
			}
		}
		else {
			throw "Syntax Error";
		}
		return arr;
	}
	ConfObject* parseObject(std::istream& in) {
		using namespace std;
		ConfObject* obj = new ConfObject;
		while (true) {
			string w;
			in >> w;
			if (w[0] == '[') {
				if (w == "[End]")
					break;
				else if (w == "[Section") {
					string name;
					in >> name;
					name = name.substr(0, name.length()-1);
					obj->Add(name, parseObject(in));
				}
				else {
					throw "Syntax Error";
				}
			}
			else {
				string name = "";
				for (int i = 0 ; i < w.length() ; i ++) {
					if(isalpha(w[i]))
						name += w[i];
					else
						break;
				}
				if (! w[name.length()] == '=') {
					throw "Syntax Error";
				}
				if (w[name.length() + 1] == '{') {
					stringstream ss(w.substr(name.length() + 1, w.length()));
					obj->Add(name, parseArray(ss));
					continue;
				}
				string value = "";
				for (int i = name.length() + 1 ; i < w.length() ; i ++) {
					if(w[i] != '\n' || w[i] != '\r')
						value += w[i];
					else
						break;
				}
				obj->Add(name, new ConfPrimitive(value));
			}
		}
		return obj;
	}
	ConfObject* parse(std::istream& in) {
		using namespace std;
		ConfObject* obj = new ConfObject;
		while (true) {
			if (in.eof())
				break;
			string w;
			in >> w;
			if (w[0] == '[') {
				if (w == "[Section") {
					string name;
					in >> name;
					name = name.substr(0, name.length()-1);
					obj->Add(name, parseObject(in));
				}
			}
		}
		return obj;
	}
}
