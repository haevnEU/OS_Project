#ifndef INTROPAGE_H
#define INTROPAGE_H

#include <QWizardPage>
#include "pages_enum.h"

/**
 * @brief The IntroPage class
 * @details This class is a custom implementation of a wizard page
 *          It provides a quick introduction about the following wizard steps
 * @author Nils Milewski (10010480)
 */
class IntroPage : public QWizardPage{
private:
    /**
     * @brief nextPage_m This variable contains the next page,
     * @details next page containt the page index which should follow. You can look into
     *          pages_enum.h for a detailed look about all possible pages. Most of the time it
     *          will be used to switch between disk and partition pages.
     */
    pages_enum nextPage_m;

public:
    /**
     * @brief IntroPage This is a constructor
     * @details This constructor creates the layout of the page and set required attributes
     * @param text Text which should be displayed to the user
     * @param nextPage Enum from the next step @see pages_enum.h
     * @param parent Parent object which this object is associated with
     */
    IntroPage(QString text, pages_enum nextPage, QWidget* parent = nullptr);

    /**
     * @brief nextId This method returns the next id
     * @details This method overrides the default implementation to utilize different intro pages.
     *          It will return the enum of next_page to differenciate between disk and partition pages
     * @return Next id for the wizard
     */
    int nextId() const override;
};

#endif // INTROPAGE_H
