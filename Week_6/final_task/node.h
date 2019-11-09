//
// Created by GAlekseyV on 21.09.2018.
//
#pragma once

#include "date.h"
#include "operations.h"

#include <string>
#include <memory>

class Node {
public:
    virtual bool Evaluate(const Date& date, const std::string& event) const = 0;

protected:

};

class EmptyNode:public Node{
public:
    bool Evaluate(const Date& date, const std::string& event) const override  {return true;}
};

class EventComparisonNode:public Node{
public:
    EventComparisonNode(Comparison operation, const std::string &event);
    bool Evaluate(const Date& date, const std::string& event) const override;

private:
    const Comparison operation_;
    const std::string event_;
};

class DateComparisonNode:public Node{
public:
    DateComparisonNode(Comparison operation, const Date &date);
    bool Evaluate(const Date& date, const std::string& event) const override;

private:
    const Comparison comparison_;
    const Date date_;
};

class LogicalOperationNode:public Node{
public:
    LogicalOperationNode(LogicalOperation operation, std::shared_ptr<Node> left, std::shared_ptr<Node> right);
    bool Evaluate(const Date& date, const std::string& event) const override;

private:
    std::shared_ptr<Node> left_, right_;
    const LogicalOperation logicalOperation_;
};
