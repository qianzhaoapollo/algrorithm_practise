
# coding: utf-8

# In[1]:


import sklearn.datasets as d


# In[7]:


blobs = d.make_blobs()


# In[4]:


from sklearn.cluster import KMeans
from scipy.spatial.distance import cdist


# In[14]:


import numpy as np
import matplotlib.pyplot as plt
K = range(1, 10)
meandistortions = []
for k in K:
    kmeans=KMeans(n_clusters=k)
    kmeans.fit(blobs[0])
    meandistortions.append(sum(np.min(
            cdist(blobs[0],kmeans.cluster_centers_,
                 'euclidean'),axis=1))/blobs[0].shape[0])
plt.plot(K,meandistortions,'bx-')
plt.xlabel('k')


# In[15]:


from sklearn.cluster import KMeans
import numpy as np
from sklearn import metrics


# In[19]:


colors = ['b', 'g', 'r', 'c', 'm', 'y', 'k', 'b']
kmeans_model=KMeans(n_clusters=3).fit(blobs[0])
for i,l in enumerate(kmeans_model.labels_):
    plt.plot(blobs[0][:,0][i],blobs[0][:,1][i],
             color=colors[l],marker='o',ls='None')
    

