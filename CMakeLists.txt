cmake_minimum_required(VERSION 3.12)
project(Yellow_belt)

set(CMAKE_CXX_STANDARD 17)

set(WEEKS
    Week_1
    Week_2
    Week_3
    Week_4
    Week_5
    Week_6
)

set(Week_1
        task_1_check
        task_2_avgTemp
        task_3_blocks
        task_4_regions_base
        task_5_teamTasks
        task_6_sqr
        task_7_link
        template_code
)

set(Week_2
        task_1_decomposition
        task_2_test_for_Get
        task_3_tests_person
        task_4_test_rational
        task_5_test_isPalindrom
        unit_test_framework
)

set(Week_3
        task_1_sum_reverse_sort
        task_2_phone_number
        task_4_dec_2
        )

set(Week_4
        task_1_parts_of_vector
        task_2_find_greater
        task_3_SplitIntoWords
        task_4_del_repeats
        task_5_permutations
        task_6_demography
        task_7.1_sort
        task_7.2_sort
        task_8_findnearest
        task_9_names_surnames_4
        task_10_1_groups
        task_10_2_groups
        task_11_1_arithm_exp
        task_11_2_arithm_exp
        )

set(Week_5
        task_1_inheritance
        task_2_notifier
        task_3_figures
        task_4_refactor
        task_5_check_refactor
        parser
        )

set(Week_6
        final_task
        solve
        )

# create a project file per tutorial
foreach(WEEK ${WEEKS})
    foreach(TASK ${${WEEK}})
        file(GLOB SOURCE
                "${WEEK}/${TASK}/*.h"
                "${WEEK}/${TASK}/*.cpp"
                )
        set(NAME "${WEEK}_${TASK}")
        add_executable(${NAME} ${SOURCE})
    endforeach(TASK)
endforeach(WEEK)