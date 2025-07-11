import streamlit as st
import pandas as pd
import numpy as np

st.set_page_config(page_title="Price Anomaly Detector", layout="centered")

st.title("🛒 Smart Price Anomaly Detector")
st.write("This app finds products with abnormal prices.")

uploaded_file = st.file_uploader("Upload a product price CSV file", type=["csv"])

if uploaded_file is not None:
    df = pd.read_csv(uploaded_file)
    
    if 'price' in df.columns:
        median = np.median(df['price'])
        mad = np.median(np.abs(df['price'] - median))

        if mad == 0:
            st.warning("MAD is zero — all prices might be the same or close. Can't detect anomalies.")
            df['is_anomaly'] = False
        else:
            df['modified_z'] = 0.6745 * (df['price'] - median) / mad
            df['is_anomaly'] = df['modified_z'].abs() > 3.5

        st.subheader("📊 All Products")
        st.dataframe(df[['product_id', 'product_name', 'price', 'is_anomaly']])

        st.subheader("⚠️ Detected Anomalies")
        anomalies = df[df['is_anomaly']]
        st.dataframe(anomalies[['product_id', 'product_name', 'price']])

        st.success(f"Detected {len(anomalies)} potential price anomalies.")
    else:
        st.error("CSV must contain a 'price' column.")



# streamlit run app.py
