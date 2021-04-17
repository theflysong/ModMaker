#include "conf_loader.h"

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
	ConfObject parse(std::string config) {
		
	}
}
