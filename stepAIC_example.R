library(MASS)
require(MASS)

df = read.csv('./R_data/telecom_dummy.csv')

cols = c()

for(i in 1:length(colnames(df))){
  cat(colnames(df)[i], '+ ')
}


model = lm(
  Churn_ ~ tenure +
    MonthlyCharges +
    TotalCharges +
    log_TotalCharges +
    SeniorCitizen_1 +
    Contract_Month_to_month +
    Contract_One_year +
    Contract_Two_year +
    PhoneService_Yes +
    DeviceProtection_Yes +
    StreamingTV_Yes +
    no_IS +
    OnlineBackup_Yes +
    StreamingMovies_Yes +
    TechSupport_Yes +
    OnlineSecurity_Yes +
    MultipleLines_Yes +
    gender_Male +
    PaymentMethod_Bank_transfer_.automatic. +
    PaymentMethod_Credit_card_.automatic. +
    PaymentMethod_Electronic_check +
    PaymentMethod_Mailed_check +
    PaperlessBilling_Yes +
    Dependents_Yes +
    Partner_Yes +
    InternetService_DSL +
    InternetService_Fiber_optic,
  data = df
)

stepAIC(model)

# lowest AIC

"
Call:
  lm(formula = Churn_ ~ tenure + TotalCharges + log_TotalCharges + 
       SeniorCitizen_1 + Contract_Month_to_month + PhoneService_Yes + 
       DeviceProtection_Yes + StreamingTV_Yes + no_IS + StreamingMovies_Yes + 
       TechSupport_Yes + OnlineSecurity_Yes + MultipleLines_Yes + 
       PaymentMethod_Electronic_check + PaperlessBilling_Yes + InternetService_DSL, 
     data = df)
"


