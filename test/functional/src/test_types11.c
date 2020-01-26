/*****************************************************************************
 * Test cases for libxlsxwriter.
 *
 * Test to compare output against Excel files.
 *
 * Copyright 2014-2020, John McNamara, jmcnamara@cpan.org
 *
 */

#include "xlsxwriter.h"

int main() {

    lxw_workbook  *workbook  = workbook_new("test_types11.xlsx");
    lxw_worksheet *worksheet = workbook_add_worksheet(workbook, NULL);
    double num = 1;
    lxw_row_t row_num;

    worksheet_set_column(worksheet, 0, 0, 32, NULL);

    for (row_num = 0; row_num < 1024; row_num++) {
        worksheet_write_number(worksheet, row_num, 0, num, NULL);
        num *= 2;
    }

    return workbook_close(workbook);
}
