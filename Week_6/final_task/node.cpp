//
// Created by GAlekseyV on 21.09.2018.
//

#include "node.h"

DateComparisonNode::DateComparisonNode(Comparison operation, const Date &date)
                                        : comparison_(operation), date_(date){

}

bool DateComparisonNode::Evaluate(const Date &date, const std::string &event) const {
    if(comparison_ == Comparison::Equal){
        return date == date_;
    }
    if(comparison_ == Comparison::NotEqual){
        return date != date_;
    }
    if(comparison_ == Comparison::Greater){
        return !(date < date_) && date != date_;
    }
    if(comparison_ == Comparison::GreaterOrEqual){
        return !(date < date_);
    }
    if(comparison_== Comparison::Less){
        return date < date_;
    }
    if(comparison_== Comparison::LessOrEqual){
        return date < date_ || date == date_;
    }
    return false;
}

EventComparisonNode::EventComparisonNode(Comparison operation, const std::string &event)
                                        : operation_(operation), event_(event){

}

bool EventComparisonNode::Evaluate(const Date &date, const std::string &event) const {
    if(operation_ == Comparison::Equal){
        return event == event_;
    }
    if(operation_ == Comparison::NotEqual){
        return event != event_;
    }
    if(operation_ == Comparison::Greater){
        return !(event < event_) && event != event_;
    }
    if(operation_ == Comparison::GreaterOrEqual){
        return !(event < event_);
    }
    if(operation_== Comparison::Less){
        return event < event_;
    }
    if(operation_== Comparison::LessOrEqual){
        return event < event_ || event == event_;
    }
    return false;
}

LogicalOperationNode::LogicalOperationNode(LogicalOperation operation, std::shared_ptr<Node> left,
                                           std::shared_ptr<Node> right)
                                           : logicalOperation_(operation),
                                             left_(left), right_(right){

}

bool LogicalOperationNode::Evaluate(const Date& date, const std::string& event) const{
    if(logicalOperation_ == LogicalOperation::And){
        return left_->Evaluate(date, event) && right_->Evaluate(date, event);
    }
    if(logicalOperation_ == LogicalOperation::Or){
        return left_->Evaluate(date, event) || right_->Evaluate(date, event);
    }
    return false;
}