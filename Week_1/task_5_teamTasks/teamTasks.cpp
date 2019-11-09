//
// Created by GAlekseyV on 12.09.2018.
//
/*
 * Реализуйте класс TeamTasks, позволяющий хранить статистику по статусам задач команды разработчиков:
 * Метод PerformPersonTasks должен реализовывать следующий алгоритм:
 * -Рассмотрим все не выполненные задачи разработчика person.
 * -Упорядочим их по статусам: сначала все задачи в статусе NEW, затем все задачи в статусе IN_PROGRESS и,
 * наконец, задачи в статусе TESTING.
 * -Рассмотрим первые task_count задач и переведём каждую из них в следующий статус в соответствии с естественным
 * порядком: NEW → IN_PROGRESS → TESTING → DONE.
 * -Вернём кортеж из двух элементов: информацию о статусах обновившихся задач (включая те, которые оказались в
 * статусе DONE) и информацию о статусах остальных не выполненных задач.
 * Гарантируется, что task_count является положительным числом. Если task_count превышает текущее количество
 * невыполненных задач разработчика, достаточно считать, что task_count равен количеству невыполненных задач:
 * дважды обновлять статус какой-либо задачи в этом случае не нужно.
 * Кроме того, гарантируется, что метод GetPersonTasksInfo не будет вызван для разработчика, не имеющего задач.
 */
#include <iostream>
#include <map>
#include <tuple>
#include <utility>

using namespace std;

//// Перечислимый тип для статуса задачи
//enum class TaskStatus {
//    NEW,          // новая
//    IN_PROGRESS,  // в разработке
//    TESTING,      // на тестировании
//    DONE          // завершена
//};
//
//// Объявляем тип-синоним для map<TaskStatus, int>,
//// позволяющего хранить количество задач каждого статуса
//using TasksInfo = map<TaskStatus, int>;

class TeamTasks {
public:
    // Получить статистику по статусам задач конкретного разработчика
    const TasksInfo& GetPersonTasksInfo(const string& person) const{
        if(storage.count(person) > 0){
            return storage.at(person);
        }
        return {};
    }

    // Добавить новую задачу (в статусе NEW) для конкретного разработчитка
    void AddNewTask(const string& person){
        ++storage[person][TaskStatus::NEW];
    }

    // Обновить статусы по данному количеству задач конкретного разработчика,
    // подробности см. ниже
    tuple<TasksInfo, TasksInfo> PerformPersonTasks(
            const string& person, int task_count){
        TasksInfo updated_tasks, untouched_tasks, new_personal_tasks;
        if(storage.count(person) > 0){
            //int carry_updated = 0;
            for(const auto& [status, num_tasks] : storage[person]){
                auto [updated, untouched] = update_tasks_in_status(status, num_tasks, task_count);
                //updated_tasks[status] = carry_updated;
                if(untouched != 0){
                    if(status != TaskStatus::DONE){
                        untouched_tasks[status] = untouched;
                    }
                    new_personal_tasks[status] += untouched;
                }else{

                }
                if(updated > 0){
                    TaskStatus next_status = TaskStatus(static_cast<int>(status) + 1);
                    updated_tasks[next_status] = updated;
                    new_personal_tasks[next_status] += updated;
                }
                //carry_updated = updated;
                task_count -= updated;
            }
        }
        storage[person] = new_personal_tasks;
        return tie(updated_tasks, untouched_tasks);
    }

private:
    pair<int, int> update_tasks_in_status(const TaskStatus& status, int num_tasks, int task_count){
        int updated = 0, untouched = num_tasks;
        if(status != TaskStatus::DONE){
            while(task_count > 0 && untouched > 0)
            {
                --task_count;
                ++updated;
                --untouched;
            }
        }
        return make_pair(updated, untouched);
    }
    map<string, TasksInfo> storage;
};


// Принимаем словарь по значению, чтобы иметь возможность
// обращаться к отсутствующим ключам с помощью [] и получать 0,
// не меняя при этом исходный словарь
void PrintTasksInfo(TasksInfo tasks_info) {
    cout << tasks_info[TaskStatus::NEW] << " new tasks" <<
         ", " << tasks_info[TaskStatus::IN_PROGRESS] << " tasks in progress" <<
         ", " << tasks_info[TaskStatus::TESTING] << " tasks are being tested" <<
         ", " << tasks_info[TaskStatus::DONE] << " tasks are done" << endl;
}

//int main() {
//    TeamTasks tasks;
//    tasks.AddNewTask("Ilia");
//    for (int i = 0; i < 5; ++i) {
//        tasks.AddNewTask("Alice");
//    }
//    cout << "Alice's tasks: ";
//    PrintTasksInfo(tasks.GetPersonTasksInfo("Alice"));
//
//    TasksInfo updated_tasks, untouched_tasks;
//
//    tie(updated_tasks, untouched_tasks) =
//            tasks.PerformPersonTasks("Alice", 5);
//    cout << "Updated Alice's tasks: ";
//    PrintTasksInfo(updated_tasks);
//    cout << "Untouched Alice's tasks: ";
//    PrintTasksInfo(untouched_tasks);
//
//    tie(updated_tasks, untouched_tasks) =
//            tasks.PerformPersonTasks("Alice", 5);
//    cout << "Updated Alice's tasks: ";
//    PrintTasksInfo(updated_tasks);
//    cout << "Untouched Alice's tasks: ";
//    PrintTasksInfo(untouched_tasks);
//
//    tie(updated_tasks, untouched_tasks) =
//            tasks.PerformPersonTasks("Alice", 1);
//    cout << "Updated Alice's tasks: ";
//    PrintTasksInfo(updated_tasks);
//    cout << "Untouched Alice's tasks: ";
//    PrintTasksInfo(untouched_tasks);
//
//    tasks.AddNewTask("Ilia");
//    for (int i = 0; i < 5; ++i) {
//        tasks.AddNewTask("Alice");
//    }
//
//    tie(updated_tasks, untouched_tasks) = tasks.PerformPersonTasks("Alice", 2);
//    cout << "Updated Alice's tasks: ";
//    PrintTasksInfo(updated_tasks);
//    cout << "Untouched Alice's tasks: ";
//    PrintTasksInfo(untouched_tasks);
//
//    cout << "Alice's tasks: ";
//    PrintTasksInfo(tasks.GetPersonTasksInfo("Alice"));
//
//    tie(updated_tasks, untouched_tasks) =
//            tasks.PerformPersonTasks("Alice", 4);
//    cout << "Updated Alice's tasks: ";
//    PrintTasksInfo(updated_tasks);
//    cout << "Untouched Alice's tasks: ";
//    PrintTasksInfo(untouched_tasks);
//
//    cout << "Alice's tasks: ";
//    PrintTasksInfo(tasks.GetPersonTasksInfo("Alice"));
//
//    return 0;
//}